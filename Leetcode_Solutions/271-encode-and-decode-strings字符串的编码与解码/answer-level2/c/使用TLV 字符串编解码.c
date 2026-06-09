#define TYPE_LEN 1
#define TYPE_STR 2
#pragma pack(1)
typedef struct _tlv {
    int type;
    int length;
    char* val[0];
}TLV;
int GetAllLength(char** strs, int strsSize)
{
    int len = 0;
    for (int i = 0; i < strsSize; i++) {
        len += strlen(strs[i]);
    }
    return len;
}
char* encode(char** strs, int strsSize) {
    
    int len = GetAllLength(strs, strsSize) + sizeof(TLV)*(strsSize + 1);
    char* buff = calloc(len, sizeof(char));
    TLV* tlv1;
    char* start = buff;
    tlv1 = (TLV*)start;
    tlv1->type = htonl(TYPE_LEN);
    tlv1->length = (strsSize);
    start += sizeof(TLV);
    for (int i = 0; i < strsSize; i++) {
       tlv1 = (TLV*)start;
       tlv1->type = htonl(TYPE_STR);
       tlv1->length = (strlen(strs[i]));
       memcpy(tlv1->val, strs[i], strlen(strs[i]));
       start += (sizeof(TLV) + strlen(strs[i]));
    }
    return buff;
}
char** decode(char* s, int* returnSize) {
    char* start = s;
    TLV* tlv = (TLV*)start;
    int allLen = tlv->length;
    char** ret = calloc(allLen + 1, sizeof(char*));
    /* 总长度 */
    start += sizeof(TLV);

    for (int i = 0; i < allLen; i++) {
        tlv = (TLV*)start;
        int len = tlv->length;
        ret[i] = calloc(len + 1, sizeof(char));
        memcpy(ret[i], tlv->val, len*sizeof(char));
        start += (sizeof(TLV) + len);
    }
    *returnSize = allLen;
    return ret;
}