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

network ForwardingNetwork
{
    parameters:
        int source;
        int destination;
//        int npackets;


        @display("bgb=441,204");
    submodules:

        node[5]: Node {
            id = index;
            source = parent.source;
            destination = parent.destination;
        }

    connections allowunconnected:
        node[0].gOut[0] --> node[1].gIn[0];
        node[0].gIn[0] <-- node[1].gOut[0];
        
        node[1].gOut[1] --> node[2].gIn[0];
        node[1].gIn[1] <-- node[2].gOut[0];
        
        node[1].gOut[2] --> node[3].gIn[1];
        node[1].gIn[2] <-- node[3].gOut[1];
        
        node[2].gOut[1] --> node[4].gIn[0];
        node[2].gIn[1] <-- node[4].gOut[0];
        
        node[4].gOut[1] --> node[3].gIn[0];
        node[4].gIn[1] <-- node[3].gOut[0];

}
