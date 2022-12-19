### 解题思路
此处撰写解题思路

### 代码

```c
void findMaxStr(char * pstr, int pos, int mod, int * start, int *end) {
    int low = 0, high = 0;  
    int invliad = 0;
    int iLen = strlen(pstr);
    low = pos;               
    high = pos + mod;
    invliad = 0;
    for(; low >= 0 && high < iLen; low--, high++) {
        if(pstr[low] != pstr[high]) {
            invliad = 1;
            break;
        }
    }
    if (low < 0) {
        low = 0;
        high--;
    }
    if(high == iLen) {
        high = iLen - 1;
        low++;
    }
    if(invliad == 1) {
        low++;
        high--;
    }
    *start = low;
    *end = high;
}

char * longestPalindrome(char * s){
    if (s == NULL || strlen(s) == 0 || (strlen(s) == 1 && s[0] != ' ')) {
        return s;
    }
    if (strlen(s) == 2 && s[0] != s[1]) {
        return s+1;
    }

    char *pstr = s;
    int iPos = 0;
    int iLen = strlen(s); 
    int index = 0;
    char *pstreturn = (char *)malloc(sizeof(char)*(iLen+1));
    if (pstreturn == NULL) {
        return NULL;
    }
    memset(pstreturn, 0, iLen+1);
    int start = 0;
    int end = 0;
    for(; iPos < iLen; iPos++) {
        if(iPos+1 < iLen && pstr[iPos] == pstr[iPos+1]) { // abba 模式
            findMaxStr(pstr, iPos, 1, &start, &end);
            if ((end - start + 1) > strlen(pstreturn)) {
                memset(pstreturn, 0, iLen+1);
                memcpy(pstreturn, (const void *)(pstr + start), end - start + 1);
            }
        }
        if(iPos+2 < iLen && pstr[iPos] == pstr[iPos+2]) { // ara 模式
            findMaxStr(pstr, iPos, 2, &start, &end);
            if ((end - start + 1) > strlen(pstreturn)) {
                memset(pstreturn, 0, iLen+1);
                memcpy(pstreturn, (const void *)(pstr + start), end - start + 1);
            }
        }        
    }
    if(strlen(pstreturn) == 0) {
        memcpy(pstreturn, (const void *)pstr, 1);
    }
    return pstreturn;
}
```