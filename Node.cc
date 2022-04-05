//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "Node.h"

Define_Module(Node);

void Node::initialize()
{
//    in=gate("gIn");
//    out=gate("gOut");
    id = par("id");
    destAdd = par("destination");
    srcAdd = par("source");


       if(id==0)
       {
           mp[1]=100;
           LUT = {{1, 0}};
       }
       if(id==1)
           {
               mp[0]=100;
               mp[2]=200;
               mp[3]=200;
               LUT = {{0, 0}, {2, 1}, {3, 2}};
           }
       if(id==2)
           {
               mp[1]=200;
               mp[4]=100;
               LUT = {{1,0}, {4,1}};
           }
       if(id==3)
       {
           mp[1]=200;
           mp[4]=200;
           LUT = {{1,1}, {4, 0}};
       }
       if(id==4)
       {
           mp[2]=100;
           mp[3]=200;
           LUT = {{3, 1}, {2, 0}};
       }
       if(id==srcAdd)
       {
           cMessage* m = new cMessage();
           scheduleAt(0, m);
       }


}

void Node::handleMessage(cMessage *msg)
{
    if(msg->isSelfMessage())
            {
                NL_pdu *data = new NL_pdu();
                data->setS(simTime());
                send(data, "gOut", LUT[destAdd]);
            }
         else
            {
                if(id==destAdd)
                {
                    NL_pdu* data = check_and_cast<NL_pdu*>(msg);
                    EV<<"Delay"<<data->getArrivalTime() - data->getS();
                }
                else
                {
//                    for(auto each:mp) {
//                        if(each.first==check_and_cast<Node*>(msg->getSenderModule())->srcAdd) {
//                            continue;
//                        }
                        NL_pdu* data = check_and_cast<NL_pdu*>(msg->dup());
                        send(data, "gOut", LUT[destAdd]);
//                    }

                }
            }

}
