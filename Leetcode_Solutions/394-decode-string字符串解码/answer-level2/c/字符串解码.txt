![截图.PNG](https://pic.leetcode-cn.com/3fdd90bcc8fda083df13fd0c13aa68b851cb6809717464a9a1a8a339114216ca-%E6%88%AA%E5%9B%BE.PNG)
```
/* 找第一个左括号对应的右括号，返回括号个数，postion为第一个左括号对应的右括号 */
int FindRightBrackets(char *s, int *leftPosition, int *rightPosition, int *numPostion)
{
    int sLen = strlen(s);
    int i, j, k;

    for (i = 0; i < sLen; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            *numPostion = i;
            break;
        }
    }
    if (i == sLen) {
        return 0;
    }

    for (i = (*numPostion) + 1; i < sLen; i++) {
        if (s[i] == '[') {
            *leftPosition = i;
            j = 1;
            k = 1;
            break;
        }
    }

    for (i = (*leftPosition) + 1; i < sLen; i++) {
        if (s[i] == '[') {
            j++;
            k++;
        } 
        if (s[i] == ']') {
            j--;
        }
        if (j == 0) {
            break;
        }
    }

    *rightPosition = i;
    return k;
}

/* 单个k[encoded_string]的解码 */
void DecodeSingle(char *result, char *s, int num, int sLen)
{
    int i;
    (void)strncpy(result, s, sLen);
    for (i = 1; i < num; i++) {
        (void)strncat(result, s, sLen);
    }
}

int CalNum(char *s)
{
    int i = 0;
    int num = 0;
    while(s[i] != '[') {
        num = (s[i] - '0') + num * 10;
        i++;
    }
    return num;
}

/* 一次解析去掉一个括号 */
void Decode(char *result, int sLen)
{
    int i, bracketsNum, leftPosition, rightPosition, numPostion, num, len;
    char *s = NULL;
    char *c = (char *)malloc(sizeof(char) * 5000);
    char *c1 = NULL;
    if (c == NULL) {
        return 0;
    }
    strcpy(c, result);
    memset(result, 0, sizeof(char) * 5000);
    bracketsNum = FindRightBrackets(c, &leftPosition, &rightPosition, &numPostion);
    if (bracketsNum == 0) {
        return;
    }
    if (numPostion == 0) {
        num = CalNum(c);
        c1 = c + leftPosition + 1;
        len = rightPosition - leftPosition - 1;
        DecodeSingle(result, c1, num, len);
        if (rightPosition != sLen - 1) {
            c1 = c + rightPosition + 1;
            strcat(result, c1);
        }
        free(c);
    } else {
        s = (char *)malloc(sizeof(char) * 5000);
        if (s == NULL) {
            return NULL;
        }
        c1 = c + numPostion;
        len = sLen - numPostion;
        strcpy(s, c1);
        Decode(s, len);
        len = numPostion;
        (void)strncpy(result, c, numPostion);
        strcat(result, s);
        free(c);
        free(s);
    }
}

char *decodeString(char * s){
    int sLen = strlen(s);
    int bracketsNum, leftPosition, rightPosition, numPostion;
    char *result;

    if (s == NULL || sLen < 4) {
        return s;
    }

    result = (char *)malloc(sizeof(char) * 5000);
    if (result == NULL) {
        return NULL;
    }
    memset(result, 0, sizeof(char) * 5000);
    (void)strcpy(result, s);

    bracketsNum = FindRightBrackets(result, &leftPosition, &rightPosition, &numPostion);
    if (bracketsNum == 0) {
        return result;
    }
    while (bracketsNum != 0) {
        Decode(result, sLen);
        sLen = strlen(result);
        bracketsNum = FindRightBrackets(result, &leftPosition, &rightPosition, &numPostion);
    }
    return result;
}
```

