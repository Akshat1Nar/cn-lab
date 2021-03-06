//
// Generated file, do not edit! Created by nedtool 5.7 from NL_pdu.msg.
//

#ifndef __NL_PDU_M_H
#define __NL_PDU_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0507
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>NL_pdu.msg:19</tt> by nedtool.
 * <pre>
 * //
 * // TODO generated message class
 * //
 * packet NL_pdu
 * {
 *     int pktid;
 *     int srcAdd;
 *     int destAdd;
 *     simtime_t s;
 * }
 * </pre>
 */
class NL_pdu : public ::omnetpp::cPacket
{
  protected:
    int pktid;
    int srcAdd;
    int destAdd;
    ::omnetpp::simtime_t s;

  private:
    void copy(const NL_pdu& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const NL_pdu&);

  public:
    NL_pdu(const char *name=nullptr, short kind=0);
    NL_pdu(const NL_pdu& other);
    virtual ~NL_pdu();
    NL_pdu& operator=(const NL_pdu& other);
    virtual NL_pdu *dup() const override {return new NL_pdu(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getPktid() const;
    virtual void setPktid(int pktid);
    virtual int getSrcAdd() const;
    virtual void setSrcAdd(int srcAdd);
    virtual int getDestAdd() const;
    virtual void setDestAdd(int destAdd);
    virtual ::omnetpp::simtime_t getS() const;
    virtual void setS(::omnetpp::simtime_t s);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const NL_pdu& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, NL_pdu& obj) {obj.parsimUnpack(b);}


#endif // ifndef __NL_PDU_M_H

