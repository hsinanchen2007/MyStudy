### 解题思路
字符串分割
先判断类型，再分别处理
    电话号码分国际和本地两种情况

### 代码

```c
#define PRELEN (2 + 5)
#define ENDLEN 1
#define STARLEN 5
#define BIG2SMALL ('a' - 'A')
#define LOCALNUM 10
#define EACHNUM 3
#define KEEPSIZE 4
#define DUPTIME 2
#define LOCALEXTRA 2
#define NATIONEXTRA 3

bool IsChar(char c)
{
    if (((c <= 'z') && (c >= 'a')) || ((c <= 'Z') && (c >= 'A'))) {
        return true;
    }
    return false;
}
int UpdatePreNum(const char* S, int pos, char* pStr)
{
    const char star = '*';
    int index = 0;
    int offset = 0;
    if ((S[index] <= 'Z') && (S[index] >= 'A')) {
        offset = ('A' - 'a');
    }
    pStr[index] = S[index] - offset;
    index++;
    for (int i = 0; i < STARLEN; i++) {
        pStr[index] = star;
        index++;
    }
    offset = 0;
    if ((S[pos] <= 'Z') && (S[pos] >= 'A')) {
        offset = BIG2SMALL;
    }
    pStr[index] = S[pos] + offset;
    index++;
    return index;
}
char *UpdateMail(const char* S)
{
    int len = strlen(S);
    const char *pKey = "@";
    char *pMatch = strstr(S, pKey);
    int retLen = (len - (pMatch - S) + PRELEN + 1);
    char* pRet = (char *)malloc(retLen);
    pRet[retLen - 1] = 0;
    int index = UpdatePreNum(S, (pMatch - S - 1), pRet);
    int offset;
    for (int i = (pMatch - S); i < len; i++) {
        offset = 0;
        if ((S[i] <= 'Z') && (S[i] >= 'A')) {
            offset = BIG2SMALL;
        }
        pRet[index] = S[i] + offset;
        index++;
    }
    return pRet;
}
int NumOfNum(const char* S)
{
    int i = 0;
    int tot = 0;
    while (S[i] != '\0') {
        if ((S[i] <= '9') && (S[i] >= '0')) {
            tot++;
        }
        i++;
    }
    return tot;
}
void UpdateLocalPhoneNum(char* pRet, int* pIndex, const char* S, int totNumLen)
{
    int len = strlen(S);
    for (int i = 0; i < DUPTIME; i++) {
        for (int j = 0; j < EACHNUM; j++) {
            pRet[*pIndex] = '*';
            (*pIndex)++;
        }
        pRet[*pIndex] = '-';
        (*pIndex)++;
    }
    for (int i = 0; i < len; i++) {
        if (totNumLen > KEEPSIZE) {
            if ((S[i] <= '9') && (S[i] >= '0')) {
                totNumLen--;
            }
            continue;
        }
        if ((S[i] <= '9') && (S[i] >= '0')) {
            pRet[*pIndex] = S[i];
            (*pIndex)++;
        }
    }
}
void UpdateNationPhoneNum(char* pRet, int* pIndex, const char* S, int totLen)
{
    pRet[*pIndex] = '+';
    (*pIndex)++;
    for (int i = 0; i < (totLen - LOCALNUM - LOCALEXTRA - LOCALEXTRA); i++) {
        pRet[*pIndex] = '*';
        (*pIndex)++;
    }
    pRet[*pIndex] = '-';
    (*pIndex)++;
}
char *UpdatePhoneNum(char* S)
{
    bool local = true;
    int len = strlen(S);
    int extLen = LOCALEXTRA;
    int totLen = NumOfNum(S);
    int totNumLen = totLen;
    if (totLen > LOCALNUM) {
        local = false;
        extLen += LOCALEXTRA;
    }
    totLen += extLen;
    char *pRet = (char *)malloc((totLen + 1) * sizeof(char));
    pRet[totLen] = 0;
    int index = 0;
    if (local == false) {
        UpdateNationPhoneNum(pRet, &index, S, totLen);
    }
    UpdateLocalPhoneNum(pRet, &index, S, totNumLen);
    return pRet;
}

char* maskPII(char* S)
{
    if (IsChar(S[0])) {
        return UpdateMail(S);
    }
    return UpdatePhoneNum(S);
}


```