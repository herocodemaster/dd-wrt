#ifndef _SQUID_FMT_BYTECODE_H
#define _SQUID_FMT_BYTECODE_H

/*
 * Squid configuration allows users to define custom formats in
 * several components.
 * - logging
 * - external ACL input
 * - deny page URL
 *
 * These enumerations and classes define the API for parsing of
 * format directives to define these patterns. Along with output
 * functionality to produce formatted buffers.
 */

namespace Format
{

/*
 * Bytecodes for the configureable format stuff
 */
typedef enum {
    LFT_NONE,			/* dummy */

    /* arbitrary string between tokens */
    LFT_STRING,

    /* client TCP connection remote end details */
    LFT_CLIENT_IP_ADDRESS,
    LFT_CLIENT_FQDN,
    LFT_CLIENT_PORT,
    LFT_CLIENT_EUI,

    /* client TCP connection local end details */
    LFT_CLIENT_LOCAL_IP,
    LFT_CLIENT_LOCAL_PORT,
    /*LFT_CLIENT_LOCAL_FQDN, (rDNS) */

    /* client connection local squid.conf details */
    LFT_LOCAL_LISTENING_IP,
    LFT_LOCAL_LISTENING_PORT,
    /*LFT_LOCAL_LISTENING_NAME, (myportname) */

    /* server TCP connection remote end details */
    LFT_SERVER_IP_ADDRESS,
    LFT_SERVER_FQDN_OR_PEER_NAME,
    LFT_SERVER_PORT,

    /* server TCP connection local end details */
    LFT_SERVER_LOCAL_IP,
    LFT_SERVER_LOCAL_IP_OLD_27,
    LFT_SERVER_LOCAL_PORT,

    /* original Request-Line details recieved from client */
    LFT_CLIENT_REQ_METHOD,
    LFT_CLIENT_REQ_URI,
    LFT_CLIENT_REQ_URLPATH,
    /* LFT_CLIENT_REQ_QUERY, */
    LFT_CLIENT_REQ_VERSION,

    /* Request-Line details recieved from client (legacy, filtered) */
    LFT_REQUEST_METHOD,
    LFT_REQUEST_URI,
    LFT_REQUEST_URLPATH_OLD_31,
    /*LFT_REQUEST_QUERY, */
    LFT_REQUEST_VERSION_OLD_2X,
    LFT_REQUEST_VERSION,

    /* request header details pre-adaptation */
    LFT_REQUEST_HEADER,
    LFT_REQUEST_HEADER_ELEM,
    LFT_REQUEST_ALL_HEADERS,

    /* request header details post-adaptation */
    LFT_ADAPTED_REQUEST_HEADER,
    LFT_ADAPTED_REQUEST_HEADER_ELEM,
    LFT_ADAPTED_REQUEST_ALL_HEADERS,

    /* Request-Line details sent to the server/peer */
    LFT_SERVER_REQ_METHOD,
    LFT_SERVER_REQ_URI,
    LFT_SERVER_REQ_URLPATH,
    /*LFT_SERVER_REQ_QUERY, */
    LFT_SERVER_REQ_VERSION,

    /* request meta details */
    LFT_REQUEST_SIZE_TOTAL,
    /*LFT_REQUEST_SIZE_LINE, */
    LFT_REQUEST_SIZE_HEADERS,
    /*LFT_REQUEST_SIZE_BODY, */
    /*LFT_REQUEST_SIZE_BODY_NO_TE, */

    /* original Status-Line details recieved from server */
    // XXX: todo

    /* Status-Line details sent to the client */
    // XXX: todo

    /* response Status-Line details (legacy, filtered) */
    LFT_HTTP_SENT_STATUS_CODE_OLD_30,
    LFT_HTTP_SENT_STATUS_CODE,
    LFT_HTTP_RECEIVED_STATUS_CODE,
    /*LFT_HTTP_STATUS, */
    LFT_HTTP_BODY_BYTES_READ,

    /* response header details pre-adaptation */
    LFT_REPLY_HEADER,
    LFT_REPLY_HEADER_ELEM,
    LFT_REPLY_ALL_HEADERS,

    /* response header details post-adaptation */
    /* LFT_ADAPTED_REPLY_HEADER, */
    /* LFT_ADAPTED_REPLY_HEADER_ELEM, */
    /* LFT_ADAPTED_REPLY_ALL_HEADERS, */

    /* response meta details */
    LFT_REPLY_SIZE_TOTAL,
    LFT_REPLY_HIGHOFFSET,
    LFT_REPLY_OBJECTSIZE,
    /*LFT_REPLY_SIZE_LINE, */
    LFT_REPLY_SIZE_HEADERS,
    /*LFT_REPLY_SIZE_BODY, */
    /*LFT_REPLY_SIZE_BODY_NO_TE, */

    /* client credentials */
    LFT_USER_NAME,   /* any source will do */
    LFT_USER_LOGIN,
    LFT_USER_IDENT,
    /*LFT_USER_REALM, */
    /*LFT_USER_SCHEME, */
    LFT_USER_EXTERNAL,
    /* LFT_USER_SSL_CERT, */

    /* global time details */
    LFT_TIME_SECONDS_SINCE_EPOCH,
    LFT_TIME_SUBSECOND,
    LFT_TIME_LOCALTIME,
    LFT_TIME_GMT,

    /* processing time details */
    LFT_TIME_TO_HANDLE_REQUEST,
    LFT_PEER_RESPONSE_TIME,
    LFT_TOTAL_SERVER_SIDE_RESPONSE_TIME,
    LFT_DNS_WAIT_TIME,

    /* Squid internal processing details */
    LFT_SQUID_STATUS,
    LFT_SQUID_ERROR,
    LFT_SQUID_ERROR_DETAIL,
    LFT_SQUID_HIERARCHY,

    LFT_MIME_TYPE,
    LFT_TAG,
    LFT_IO_SIZE_TOTAL,
    LFT_EXT_LOG,

    LFT_SEQUENCE_NUMBER,

#if USE_ADAPTATION
    LFT_ADAPTATION_SUM_XACT_TIMES,
    LFT_ADAPTATION_ALL_XACT_TIMES,
    LFT_ADAPTATION_LAST_HEADER,
    LFT_ADAPTATION_LAST_HEADER_ELEM,
    LFT_ADAPTATION_LAST_ALL_HEADERS,
#endif

#if ICAP_CLIENT

    LFT_ICAP_TOTAL_TIME,

    LFT_ICAP_ADDR,
    LFT_ICAP_SERV_NAME,
    LFT_ICAP_REQUEST_URI,
    LFT_ICAP_REQUEST_METHOD,
    LFT_ICAP_BYTES_SENT,
    LFT_ICAP_BYTES_READ,
    LFT_ICAP_BODY_BYTES_READ,

    LFT_ICAP_REQ_HEADER,
    LFT_ICAP_REQ_HEADER_ELEM,
    LFT_ICAP_REQ_ALL_HEADERS,

    LFT_ICAP_REP_HEADER,
    LFT_ICAP_REP_HEADER_ELEM,
    LFT_ICAP_REP_ALL_HEADERS,

    LFT_ICAP_TR_RESPONSE_TIME,
    LFT_ICAP_IO_TIME,
    LFT_ICAP_OUTCOME,
    LFT_ICAP_STATUS_CODE,
#endif

#if USE_SSL
    LFT_SSL_BUMP_MODE,
    LFT_SSL_USER_CERT_SUBJECT,
    LFT_SSL_USER_CERT_ISSUER,
#endif

    LFT_PERCENT			/* special string cases for escaped chars */
} ByteCode_t;

/// Quoting style for a format output.
enum Quoting {
    LOG_QUOTE_NONE = 0,
    LOG_QUOTE_QUOTES,
    LOG_QUOTE_MIMEBLOB,
    LOG_QUOTE_URL,
    LOG_QUOTE_RAW
};

extern const char *log_tags[];

} // namespace Format

#endif /* _SQUID_FMT_BYTECODE_H */
