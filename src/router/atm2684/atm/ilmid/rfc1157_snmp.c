/*
 *    rfc1157_snmp.c
 *
 *    "RFC1157-SNMP" ASN.1 module encode/decode/print/free C src.
 *
 *    This file was generated by snacc on Fri Jan 31 14:49:02 1997
 *
 *    UBC snacc written by Mike Sample
 *
 *    NOTE: This is a machine generated file - editing not recommended
 */



#include "asn_incl.h"
#include "rfc1155_smi.h"
#include "rfc1157_snmp.h"


AsnLen
BEncVarBindContent PARAMS((b, v),
BUF_TYPE b _AND_
VarBind* v)
{
    AsnLen totalLen = 0;
    AsnLen itemLen;
    AsnLen listLen;
    void* component;

    itemLen = BEncObjectSyntaxContent( b, (v->value));

    totalLen += itemLen;

    itemLen = BEncObjectNameContent( b, (&v->name));
    itemLen += BEncDefLen( b, itemLen);
    itemLen += BEncTag1(b, UNIV, PRIM, 6);

    totalLen += itemLen;

    return (totalLen);

}  /* BEncVarBindContent */

void
BDecVarBindContent PARAMS((b, tagId0, elmtLen0, v, bytesDecoded, env),
BUF_TYPE b _AND_
AsnTag tagId0 _AND_
AsnLen elmtLen0 _AND_
VarBind* v _AND_
AsnLen* bytesDecoded _AND_
ENV_TYPE env)
{
    int seqDone = FALSE;
    AsnLen totalElmtsLen1 = 0;
    AsnLen elmtLen1;
    AsnTag tagId1;
    int mandatoryElmtCount1 = 0;
    AsnLen totalElmtsLen2 = 0;
    AsnLen elmtLen2;
    AsnTag tagId2;


    tagId1 = BDecTag(b, &totalElmtsLen1, env);

    if ((( tagId1 == MAKE_TAG_ID( UNIV, PRIM, OID_TAG_CODE))))
    {
    elmtLen1 = BDecLen (b, &totalElmtsLen1, env);
    BDecObjectNameContent( b, tagId1, elmtLen1, (&v->name), &totalElmtsLen1, env);
    tagId1 = BDecTag(b, &totalElmtsLen1, env);
    }
    else
        longjmp(env, -100);


    if ((( tagId1 == MAKE_TAG_ID( UNIV, PRIM, INTEGER_TAG_CODE)) ||
     ( tagId1 ==MAKE_TAG_ID( UNIV, PRIM, OCTETSTRING_TAG_CODE))||
    ( tagId1 == MAKE_TAG_ID( UNIV, CONS, OCTETSTRING_TAG_CODE)) ||
     ( tagId1 ==MAKE_TAG_ID( UNIV, PRIM, OID_TAG_CODE)) ||
     ( tagId1 ==MAKE_TAG_ID( UNIV, PRIM, NULLTYPE_TAG_CODE)) ||
    ( tagId1 == MAKE_TAG_ID( APPL, PRIM, 0))||
    ( tagId1 == MAKE_TAG_ID( APPL, CONS, 0)) ||
    ( tagId1 == MAKE_TAG_ID( APPL, PRIM, 1)) ||
    ( tagId1 == MAKE_TAG_ID( APPL, PRIM, 2)) ||
    ( tagId1 == MAKE_TAG_ID( APPL, PRIM, 3)) ||
    ( tagId1 == MAKE_TAG_ID( APPL, PRIM, 4))||
    ( tagId1 == MAKE_TAG_ID( APPL, CONS, 4))))
    {
        elmtLen1 = BDecLen (b, &totalElmtsLen1, env);
    (v->value) = (ObjectSyntax*) Asn1Alloc(sizeof(ObjectSyntax));
    CheckAsn1Alloc((v->value), env);
    BDecObjectSyntaxContent( b, tagId1, elmtLen1, (v->value), &totalElmtsLen1, env);
        seqDone = TRUE;
        if ( elmtLen0 == INDEFINITE_LEN )
            BDecEoc(b, &totalElmtsLen1, env);
        else if (totalElmtsLen1 != elmtLen0)
            longjmp(env, -101);
    }
    else
        longjmp(env, -102);


    if (!seqDone)
        longjmp(env, -103);

    (*bytesDecoded) += totalElmtsLen1;
}  /* BDecVarBindContent */

void
PrintVarBind PARAMS((f, v, indent),
FILE* f _AND_
VarBind* v _AND_
unsigned short int indent)
{
    if (v == NULL)
        return;

    fprintf(f,"{ -- SEQUENCE --\n");

    Indent(f, indent + stdIndentG);
    fprintf(f,"name ");
    PrintObjectName(f, (&v->name), indent + stdIndentG);
    fprintf(f, ",\n");
    Indent(f, indent + stdIndentG);
    fprintf(f,"value ");
    PrintObjectSyntax(f, (v->value), indent + stdIndentG);
    fprintf(f,"\n");
    Indent(f, indent);
    fprintf(f,"}");
}  /* PrintVarBind */




AsnLen
BEncVarBindListContent PARAMS((b, v),
BUF_TYPE b _AND_
VarBindList* v)
{
    AsnLen totalLen = 0;
    AsnLen itemLen;
    AsnLen listLen;
    void* component;

        listLen = 0;
    FOR_EACH_LIST_ELMT_RVS( component, v)
    {
    BEncEocIfNec(b);
    itemLen = BEncVarBindContent( b, component);
    itemLen += BEncConsLen( b, itemLen);
    itemLen += BEncTag1(b, UNIV, CONS, 16);

        listLen += itemLen;
    }
    return (listLen);

}  /* BEncVarBindListContent */

void
BDecVarBindListContent PARAMS((b, tagId0, elmtLen0, v, bytesDecoded, env),
BUF_TYPE b _AND_
AsnTag tagId0 _AND_
AsnLen elmtLen0 _AND_
VarBindList* v _AND_
AsnLen* bytesDecoded _AND_
ENV_TYPE env)
{
    int seqDone = FALSE;
    AsnLen totalElmtsLen1 = 0;
    AsnLen elmtLen1;
    AsnTag tagId1;
    int mandatoryElmtCount1 = 0;


    for ( totalElmtsLen1 = 0; (totalElmtsLen1 < elmtLen0) || (elmtLen0 == INDEFINITE_LEN);)
    {
        VarBind** tmpVar;
    tagId1 = BDecTag(b, &totalElmtsLen1, env);

    if ( (tagId1 == EOC_TAG_ID) && (elmtLen0 == INDEFINITE_LEN))
    {
        BDEC_2ND_EOC_OCTET(b, &totalElmtsLen1, env)
        break; /* got EOC so can exit this SET OF/SEQ OF's for loop*/
    }
    if ( (tagId1 == MAKE_TAG_ID( UNIV, CONS, SEQ_TAG_CODE)))
    {
        elmtLen1 = BDecLen (b, &totalElmtsLen1, env);
    tmpVar = (VarBind**) AsnListAppend(v);
    (*tmpVar) = (VarBind*) Asn1Alloc(sizeof(VarBind));
    CheckAsn1Alloc((*tmpVar), env);
    BDecVarBindContent( b, tagId1, elmtLen1, (*tmpVar), &totalElmtsLen1, env);
    }  /* end of tag check if */
    else  /* wrong tag */
    {
         Asn1Error("Unexpected Tag\n");
         longjmp(env, -104);
    }
    } /* end of for */

    (*bytesDecoded) += totalElmtsLen1;
}  /* BDecVarBindListContent */

void
PrintVarBindList PARAMS((f, v, indent),
FILE* f _AND_
VarBindList* v _AND_
unsigned short int indent)
{
    VarBind* tmp;
    if (v == NULL)
        return;
    fprintf(f,"{ -- SEQUENCE OF -- \n");
    FOR_EACH_LIST_ELMT(tmp, v)
    {
        Indent(f, indent+ stdIndentG);
        PrintVarBind(f, tmp, indent + stdIndentG);
        if (tmp != (VarBind*)LAST_LIST_ELMT(v))
            fprintf(f,",\n");
    }
    fprintf(f,"\n");
    Indent(f, indent);
    fprintf(f,"}");
}  /* PrintVarBindList */




AsnLen
BEncPDUContent PARAMS((b, v),
BUF_TYPE b _AND_
PDU* v)
{
    AsnLen totalLen = 0;
    AsnLen itemLen;
    AsnLen listLen;
    void* component;

    BEncEocIfNec(b);
    itemLen = BEncVarBindListContent( b, (v->variable_bindings));
    itemLen += BEncConsLen( b, itemLen);
    itemLen += BEncTag1(b, UNIV, CONS, 16);

    totalLen += itemLen;

    itemLen = BEncAsnIntContent( b, (&v->error_index));
    BEncDefLenTo127( b, itemLen);
    itemLen++;
    itemLen += BEncTag1(b, UNIV, PRIM, 2);

    totalLen += itemLen;

    itemLen = BEncPDUIntContent( b, (&v->error_status));
    BEncDefLenTo127( b, itemLen);
    itemLen++;
    itemLen += BEncTag1(b, UNIV, PRIM, 2);

    totalLen += itemLen;

    itemLen = BEncAsnIntContent( b, (&v->request_id));
    BEncDefLenTo127( b, itemLen);
    itemLen++;
    itemLen += BEncTag1(b, UNIV, PRIM, 2);

    totalLen += itemLen;

    return (totalLen);

}  /* BEncPDUContent */

void
BDecPDUContent PARAMS((b, tagId0, elmtLen0, v, bytesDecoded, env),
BUF_TYPE b _AND_
AsnTag tagId0 _AND_
AsnLen elmtLen0 _AND_
PDU* v _AND_
AsnLen* bytesDecoded _AND_
ENV_TYPE env)
{
    int seqDone = FALSE;
    AsnLen totalElmtsLen1 = 0;
    AsnLen elmtLen1;
    AsnTag tagId1;
    int mandatoryElmtCount1 = 0;


    tagId1 = BDecTag(b, &totalElmtsLen1, env);

    if ((( tagId1 == MAKE_TAG_ID( UNIV, PRIM, INTEGER_TAG_CODE))))
    {
    elmtLen1 = BDecLen (b, &totalElmtsLen1, env);
    BDecAsnIntContent( b, tagId1, elmtLen1, (&v->request_id), &totalElmtsLen1, env);
    tagId1 = BDecTag(b, &totalElmtsLen1, env);
    }
    else
        longjmp(env, -105);


    if ((( tagId1 == MAKE_TAG_ID( UNIV, PRIM, INTEGER_TAG_CODE))))
    {
    elmtLen1 = BDecLen (b, &totalElmtsLen1, env);
    BDecPDUIntContent( b, tagId1, elmtLen1, (&v->error_status), &totalElmtsLen1, env);
    tagId1 = BDecTag(b, &totalElmtsLen1, env);
    }
    else
        longjmp(env, -106);


    if ((( tagId1 == MAKE_TAG_ID( UNIV, PRIM, INTEGER_TAG_CODE))))
    {
    elmtLen1 = BDecLen (b, &totalElmtsLen1, env);
    BDecAsnIntContent( b, tagId1, elmtLen1, (&v->error_index), &totalElmtsLen1, env);
    tagId1 = BDecTag(b, &totalElmtsLen1, env);
    }
    else
        longjmp(env, -107);


    if ((( tagId1 == MAKE_TAG_ID( UNIV, CONS, SEQ_TAG_CODE))))
    {
    elmtLen1 = BDecLen (b, &totalElmtsLen1, env);
    (v->variable_bindings) = AsnListNew(sizeof(char*));
    CheckAsn1Alloc((v->variable_bindings), env);
    BDecVarBindListContent( b, tagId1, elmtLen1, (v->variable_bindings), &totalElmtsLen1, env);
        seqDone = TRUE;
        if ( elmtLen0 == INDEFINITE_LEN )
            BDecEoc(b, &totalElmtsLen1, env);
        else if (totalElmtsLen1 != elmtLen0)
            longjmp(env, -108);
    }
    else
        longjmp(env, -109);


    if (!seqDone)
        longjmp(env, -110);

    (*bytesDecoded) += totalElmtsLen1;
}  /* BDecPDUContent */

void
PrintPDU PARAMS((f, v, indent),
FILE* f _AND_
PDU* v _AND_
unsigned short int indent)
{
    if (v == NULL)
        return;

    fprintf(f,"{ -- SEQUENCE --\n");

    Indent(f, indent + stdIndentG);
    fprintf(f,"request-id ");
    PrintAsnInt(f, (&v->request_id), indent + stdIndentG);
    fprintf(f, ",\n");
    Indent(f, indent + stdIndentG);
    fprintf(f,"error-status ");
    PrintPDUInt(f, (&v->error_status), indent + stdIndentG);
    fprintf(f, ",\n");
    Indent(f, indent + stdIndentG);
    fprintf(f,"error-index ");
    PrintAsnInt(f, (&v->error_index), indent + stdIndentG);
    fprintf(f, ",\n");
    Indent(f, indent + stdIndentG);
    fprintf(f,"variable-bindings ");
    PrintVarBindList(f, (v->variable_bindings), indent + stdIndentG);
    fprintf(f,"\n");
    Indent(f, indent);
    fprintf(f,"}");
}  /* PrintPDU */




AsnLen
BEncTrap_PDUContent PARAMS((b, v),
BUF_TYPE b _AND_
Trap_PDU* v)
{
    AsnLen totalLen = 0;
    AsnLen itemLen;
    AsnLen listLen;
    void* component;

    BEncEocIfNec(b);
    itemLen = BEncVarBindListContent( b, (v->variable_bindings));
    itemLen += BEncConsLen( b, itemLen);
    itemLen += BEncTag1(b, UNIV, CONS, 16);

    totalLen += itemLen;

    itemLen = BEncTimeTicksContent( b, (&v->time_stamp));
    BEncDefLenTo127( b, itemLen);
    itemLen++;
    itemLen += BEncTag1(b, APPL, PRIM, 3);

    totalLen += itemLen;

    itemLen = BEncAsnIntContent( b, (&v->specific_trap));
    BEncDefLenTo127( b, itemLen);
    itemLen++;
    itemLen += BEncTag1(b, UNIV, PRIM, 2);

    totalLen += itemLen;

    itemLen = BEncTrap_PDUIntContent( b, (&v->generic_trap));
    BEncDefLenTo127( b, itemLen);
    itemLen++;
    itemLen += BEncTag1(b, UNIV, PRIM, 2);

    totalLen += itemLen;

    itemLen = BEncNetworkAddressContent( b, (v->agent_addr));

    totalLen += itemLen;

    itemLen = BEncAsnOidContent( b, (&v->enterprise));
    itemLen += BEncDefLen( b, itemLen);
    itemLen += BEncTag1(b, UNIV, PRIM, 6);

    totalLen += itemLen;

    return (totalLen);

}  /* BEncTrap_PDUContent */

void
BDecTrap_PDUContent PARAMS((b, tagId0, elmtLen0, v, bytesDecoded, env),
BUF_TYPE b _AND_
AsnTag tagId0 _AND_
AsnLen elmtLen0 _AND_
Trap_PDU* v _AND_
AsnLen* bytesDecoded _AND_
ENV_TYPE env)
{
    int seqDone = FALSE;
    AsnLen totalElmtsLen1 = 0;
    AsnLen elmtLen1;
    AsnTag tagId1;
    int mandatoryElmtCount1 = 0;
    AsnLen totalElmtsLen2 = 0;
    AsnLen elmtLen2;
    AsnTag tagId2;


    tagId1 = BDecTag(b, &totalElmtsLen1, env);

    if ((( tagId1 == MAKE_TAG_ID( UNIV, PRIM, OID_TAG_CODE))))
    {
    elmtLen1 = BDecLen (b, &totalElmtsLen1, env);
    BDecAsnOidContent( b, tagId1, elmtLen1, (&v->enterprise), &totalElmtsLen1, env);
    tagId1 = BDecTag(b, &totalElmtsLen1, env);
    }
    else
        longjmp(env, -111);


    if ((( tagId1 == MAKE_TAG_ID( APPL, PRIM, 0)) ||
( tagId1 == MAKE_TAG_ID( APPL, CONS, 0))))
    {
        elmtLen1 = BDecLen (b, &totalElmtsLen1, env);
    (v->agent_addr) = (NetworkAddress*) Asn1Alloc(sizeof(NetworkAddress));
    CheckAsn1Alloc((v->agent_addr), env);
    BDecNetworkAddressContent( b, tagId1, elmtLen1, (v->agent_addr), &totalElmtsLen1, env);
    tagId1 = BDecTag(b, &totalElmtsLen1, env);
    }
    else
        longjmp(env, -112);


    if ((( tagId1 == MAKE_TAG_ID( UNIV, PRIM, INTEGER_TAG_CODE))))
    {
    elmtLen1 = BDecLen (b, &totalElmtsLen1, env);
    BDecTrap_PDUIntContent( b, tagId1, elmtLen1, (&v->generic_trap), &totalElmtsLen1, env);
    tagId1 = BDecTag(b, &totalElmtsLen1, env);
    }
    else
        longjmp(env, -113);


    if ((( tagId1 == MAKE_TAG_ID( UNIV, PRIM, INTEGER_TAG_CODE))))
    {
    elmtLen1 = BDecLen (b, &totalElmtsLen1, env);
    BDecAsnIntContent( b, tagId1, elmtLen1, (&v->specific_trap), &totalElmtsLen1, env);
    tagId1 = BDecTag(b, &totalElmtsLen1, env);
    }
    else
        longjmp(env, -114);


    if ((( tagId1 == MAKE_TAG_ID( APPL, PRIM, 3))))
    {
    elmtLen1 = BDecLen (b, &totalElmtsLen1, env);
    BDecTimeTicksContent( b, tagId1, elmtLen1, (&v->time_stamp), &totalElmtsLen1, env);
    tagId1 = BDecTag(b, &totalElmtsLen1, env);
    }
    else
        longjmp(env, -115);


    if ((( tagId1 == MAKE_TAG_ID( UNIV, CONS, SEQ_TAG_CODE))))
    {
    elmtLen1 = BDecLen (b, &totalElmtsLen1, env);
    (v->variable_bindings) = AsnListNew(sizeof(char*));
    CheckAsn1Alloc((v->variable_bindings), env);
    BDecVarBindListContent( b, tagId1, elmtLen1, (v->variable_bindings), &totalElmtsLen1, env);
        seqDone = TRUE;
        if ( elmtLen0 == INDEFINITE_LEN )
            BDecEoc(b, &totalElmtsLen1, env);
        else if (totalElmtsLen1 != elmtLen0)
            longjmp(env, -116);
    }
    else
        longjmp(env, -117);


    if (!seqDone)
        longjmp(env, -118);

    (*bytesDecoded) += totalElmtsLen1;
}  /* BDecTrap_PDUContent */

void
PrintTrap_PDU PARAMS((f, v, indent),
FILE* f _AND_
Trap_PDU* v _AND_
unsigned short int indent)
{
    if (v == NULL)
        return;

    fprintf(f,"{ -- SEQUENCE --\n");

    Indent(f, indent + stdIndentG);
    fprintf(f,"enterprise ");
    PrintAsnOid(f, (&v->enterprise), indent + stdIndentG);
    fprintf(f, ",\n");
    Indent(f, indent + stdIndentG);
    fprintf(f,"agent-addr ");
    PrintNetworkAddress(f, (v->agent_addr), indent + stdIndentG);
    fprintf(f, ",\n");
    Indent(f, indent + stdIndentG);
    fprintf(f,"generic-trap ");
    PrintTrap_PDUInt(f, (&v->generic_trap), indent + stdIndentG);
    fprintf(f, ",\n");
    Indent(f, indent + stdIndentG);
    fprintf(f,"specific-trap ");
    PrintAsnInt(f, (&v->specific_trap), indent + stdIndentG);
    fprintf(f, ",\n");
    Indent(f, indent + stdIndentG);
    fprintf(f,"time-stamp ");
    PrintTimeTicks(f, (&v->time_stamp), indent + stdIndentG);
    fprintf(f, ",\n");
    Indent(f, indent + stdIndentG);
    fprintf(f,"variable-bindings ");
    PrintVarBindList(f, (v->variable_bindings), indent + stdIndentG);
    fprintf(f,"\n");
    Indent(f, indent);
    fprintf(f,"}");
}  /* PrintTrap_PDU */




AsnLen
BEncPDUsContent PARAMS((b, v),
BUF_TYPE b _AND_
PDUs* v)
{
    AsnLen totalLen = 0;
    AsnLen itemLen;
    AsnLen listLen;
    void* component;

    switch(v->choiceId)
    {
       case(PDUS_GET_REQUEST):
    BEncEocIfNec(b);
    itemLen = BEncGetRequest_PDUContent( b, (v->a.get_request));
    itemLen += BEncConsLen( b, itemLen);
    itemLen += BEncTag1(b, CNTX, CONS, 0);

    totalLen += itemLen;

    break;

       case(PDUS_GET_NEXT_REQUEST):
    BEncEocIfNec(b);
    itemLen = BEncGetNextRequest_PDUContent( b, (v->a.get_next_request));
    itemLen += BEncConsLen( b, itemLen);
    itemLen += BEncTag1(b, CNTX, CONS, 1);

    totalLen += itemLen;

    break;

       case(PDUS_GET_RESPONSE):
    BEncEocIfNec(b);
    itemLen = BEncGetResponse_PDUContent( b, (v->a.get_response));
    itemLen += BEncConsLen( b, itemLen);
    itemLen += BEncTag1(b, CNTX, CONS, 2);

    totalLen += itemLen;

    break;

       case(PDUS_SET_REQUEST):
    BEncEocIfNec(b);
    itemLen = BEncSetRequest_PDUContent( b, (v->a.set_request));
    itemLen += BEncConsLen( b, itemLen);
    itemLen += BEncTag1(b, CNTX, CONS, 3);

    totalLen += itemLen;

    break;

       case(PDUS_TRAP):
    BEncEocIfNec(b);
    itemLen = BEncTrap_PDUContent( b, (v->a.trap));
    itemLen += BEncConsLen( b, itemLen);
    itemLen += BEncTag1(b, CNTX, CONS, 4);

    totalLen += itemLen;

    break;

    }
    return (totalLen);

}  /* BEncPDUsContent */

void
BDecPDUsContent PARAMS((b, tagId0, elmtLen0, v, bytesDecoded, env),
BUF_TYPE b _AND_
AsnTag tagId0 _AND_
AsnLen elmtLen0 _AND_
PDUs* v _AND_
AsnLen* bytesDecoded _AND_
ENV_TYPE env)
{
    int seqDone = FALSE;
    AsnLen totalElmtsLen1 = 0;
    AsnLen elmtLen1;
    AsnTag tagId1;
    int mandatoryElmtCount1 = 0;


    switch(tagId0)
    {
       case(MAKE_TAG_ID( CNTX, CONS, 0)):
        (v->choiceId) = PDUS_GET_REQUEST;
    (v->a.get_request) = (GetRequest_PDU*) Asn1Alloc(sizeof(GetRequest_PDU));
    CheckAsn1Alloc((v->a.get_request), env);
    BDecGetRequest_PDUContent( b, tagId0, elmtLen0, (v->a.get_request), &totalElmtsLen1, env);
    break;

       case(MAKE_TAG_ID( CNTX, CONS, 1)):
        (v->choiceId) = PDUS_GET_NEXT_REQUEST;
    (v->a.get_next_request) = (GetNextRequest_PDU*) Asn1Alloc(sizeof(GetNextRequest_PDU));
    CheckAsn1Alloc((v->a.get_next_request), env);
    BDecGetNextRequest_PDUContent( b, tagId0, elmtLen0, (v->a.get_next_request), &totalElmtsLen1, env);
    break;

       case(MAKE_TAG_ID( CNTX, CONS, 2)):
        (v->choiceId) = PDUS_GET_RESPONSE;
    (v->a.get_response) = (GetResponse_PDU*) Asn1Alloc(sizeof(GetResponse_PDU));
    CheckAsn1Alloc((v->a.get_response), env);
    BDecGetResponse_PDUContent( b, tagId0, elmtLen0, (v->a.get_response), &totalElmtsLen1, env);
    break;

       case(MAKE_TAG_ID( CNTX, CONS, 3)):
        (v->choiceId) = PDUS_SET_REQUEST;
    (v->a.set_request) = (SetRequest_PDU*) Asn1Alloc(sizeof(SetRequest_PDU));
    CheckAsn1Alloc((v->a.set_request), env);
    BDecSetRequest_PDUContent( b, tagId0, elmtLen0, (v->a.set_request), &totalElmtsLen1, env);
    break;

       case(MAKE_TAG_ID( CNTX, CONS, 4)):
        (v->choiceId) = PDUS_TRAP;
    (v->a.trap) = (Trap_PDU*) Asn1Alloc(sizeof(Trap_PDU));
    CheckAsn1Alloc((v->a.trap), env);
    BDecTrap_PDUContent( b, tagId0, elmtLen0, (v->a.trap), &totalElmtsLen1, env);
    break;

    default:
        Asn1Error("ERROR - unexpected tag in CHOICE\n");
        longjmp(env, -119);
        break;
    } /* end switch */
    (*bytesDecoded) += totalElmtsLen1;
}  /* BDecPDUsContent */

void
PrintPDUs PARAMS((f, v, indent),
FILE* f _AND_
PDUs* v _AND_
unsigned short int indent)
{
    switch(v->choiceId)
    {
      case(PDUS_GET_REQUEST):
          fprintf(f,"get-request ");
    PrintGetRequest_PDU(f, (v->a.get_request), indent + stdIndentG);
          break;

      case(PDUS_GET_NEXT_REQUEST):
          fprintf(f,"get-next-request ");
    PrintGetNextRequest_PDU(f, (v->a.get_next_request), indent + stdIndentG);
          break;

      case(PDUS_GET_RESPONSE):
          fprintf(f,"get-response ");
    PrintGetResponse_PDU(f, (v->a.get_response), indent + stdIndentG);
          break;

      case(PDUS_SET_REQUEST):
          fprintf(f,"set-request ");
    PrintSetRequest_PDU(f, (v->a.set_request), indent + stdIndentG);
          break;

      case(PDUS_TRAP):
          fprintf(f,"trap ");
    PrintTrap_PDU(f, (v->a.trap), indent + stdIndentG);
          break;

    }
}  /* PrintPDUs */




AsnLen BEncMessage PARAMS((b, v),
BUF_TYPE b _AND_
Message* v)
{
    AsnLen l;
    BEncEocIfNec(b);
    l = BEncMessageContent(b, v);
    l += BEncConsLen(b, l);
    l += BEncTag1(b, UNIV, CONS, SEQ_TAG_CODE);
    return(l);
} /* BEncMessage */

void BDecMessage PARAMS((b, result, bytesDecoded, env),
BUF_TYPE b _AND_
Message* result _AND_
AsnLen* bytesDecoded _AND_
ENV_TYPE env)
{
    AsnTag tag;
    AsnLen elmtLen1;

    if ( ((tag = BDecTag(b, bytesDecoded, env)) != 
MAKE_TAG_ID(UNIV, CONS, SEQ_TAG_CODE)))
    {
        Asn1Error("BDecMessage: ERROR - wrong tag\n");
        longjmp(env, -120);
    }
    elmtLen1 = BDecLen(b, bytesDecoded, env);
    BDecMessageContent(b, tag, elmtLen1, result, bytesDecoded, env);
}  /* BDecMessage */

AsnLen
BEncMessageContent PARAMS((b, v),
BUF_TYPE b _AND_
Message* v)
{
    AsnLen totalLen = 0;
    AsnLen itemLen;
    AsnLen listLen;
    void* component;

    itemLen = BEncPDUsContent( b, (v->data));

    totalLen += itemLen;

    itemLen = BEncAsnOctsContent( b, (&v->community));
    itemLen += BEncDefLen( b, itemLen);
    itemLen += BEncTag1(b, UNIV, PRIM, 4);

    totalLen += itemLen;

    itemLen = BEncMessageIntContent( b, (&v->version));
    BEncDefLenTo127( b, itemLen);
    itemLen++;
    itemLen += BEncTag1(b, UNIV, PRIM, 2);

    totalLen += itemLen;

    return (totalLen);

}  /* BEncMessageContent */

void
BDecMessageContent PARAMS((b, tagId0, elmtLen0, v, bytesDecoded, env),
BUF_TYPE b _AND_
AsnTag tagId0 _AND_
AsnLen elmtLen0 _AND_
Message* v _AND_
AsnLen* bytesDecoded _AND_
ENV_TYPE env)
{
    int seqDone = FALSE;
    AsnLen totalElmtsLen1 = 0;
    AsnLen elmtLen1;
    AsnTag tagId1;
    int mandatoryElmtCount1 = 0;
    AsnLen totalElmtsLen2 = 0;
    AsnLen elmtLen2;
    AsnTag tagId2;


    tagId1 = BDecTag(b, &totalElmtsLen1, env);

    if ((( tagId1 == MAKE_TAG_ID( UNIV, PRIM, INTEGER_TAG_CODE))))
    {
    elmtLen1 = BDecLen (b, &totalElmtsLen1, env);
    BDecMessageIntContent( b, tagId1, elmtLen1, (&v->version), &totalElmtsLen1, env);
    tagId1 = BDecTag(b, &totalElmtsLen1, env);
    }
    else
        longjmp(env, -121);


    if ((( tagId1 == MAKE_TAG_ID( UNIV, PRIM, OCTETSTRING_TAG_CODE)) ||
( tagId1 == MAKE_TAG_ID( UNIV, CONS, OCTETSTRING_TAG_CODE))))
    {
    elmtLen1 = BDecLen (b, &totalElmtsLen1, env);
    BDecAsnOctsContent( b, tagId1, elmtLen1, (&v->community), &totalElmtsLen1, env);
    tagId1 = BDecTag(b, &totalElmtsLen1, env);
    }
    else
        longjmp(env, -122);


    if ((( tagId1 == MAKE_TAG_ID( CNTX, CONS, 0)) ||
    ( tagId1 == MAKE_TAG_ID( CNTX, CONS, 1)) ||
    ( tagId1 == MAKE_TAG_ID( CNTX, CONS, 2)) ||
    ( tagId1 == MAKE_TAG_ID( CNTX, CONS, 3)) ||
    ( tagId1 == MAKE_TAG_ID( CNTX, CONS, 4))))
    {
        elmtLen1 = BDecLen (b, &totalElmtsLen1, env);
    (v->data) = (PDUs*) Asn1Alloc(sizeof(PDUs));
    CheckAsn1Alloc((v->data), env);
    BDecPDUsContent( b, tagId1, elmtLen1, (v->data), &totalElmtsLen1, env);
        seqDone = TRUE;
        if ( elmtLen0 == INDEFINITE_LEN )
            BDecEoc(b, &totalElmtsLen1, env);
        else if (totalElmtsLen1 != elmtLen0)
            longjmp(env, -123);
    }
    else
        longjmp(env, -124);


    if (!seqDone)
        longjmp(env, -125);

    (*bytesDecoded) += totalElmtsLen1;
}  /* BDecMessageContent */

void
PrintMessage PARAMS((f, v, indent),
FILE* f _AND_
Message* v _AND_
unsigned short int indent)
{
    if (v == NULL)
        return;

    fprintf(f,"{ -- SEQUENCE --\n");

    Indent(f, indent + stdIndentG);
    fprintf(f,"version ");
    PrintMessageInt(f, (&v->version), indent + stdIndentG);
    fprintf(f, ",\n");
    Indent(f, indent + stdIndentG);
    fprintf(f,"community ");
    PrintAsnOcts(f, (&v->community), indent + stdIndentG);
    fprintf(f, ",\n");
    Indent(f, indent + stdIndentG);
    fprintf(f,"data ");
    PrintPDUs(f, (v->data), indent + stdIndentG);
    fprintf(f,"\n");
    Indent(f, indent);
    fprintf(f,"}\n");
}  /* PrintMessage */




