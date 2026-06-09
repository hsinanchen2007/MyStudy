![F985B738-DAA9-4D5B-A830-B32E0C366E2C.jpeg](https://pic.leetcode-cn.com/3704c9ba4edd60e27ede4a2952e8c05e82990b816cf9ac070184e3d1dd959f9e-F985B738-DAA9-4D5B-A830-B32E0C366E2C.jpeg)

```
// 1----11
// 2----12
//11----21
//字符串替换而已
#define MAXSIZE 5000

char * countAndSay(int n)
{
    int i;
    int nCpy = n;
    char *returnStr = (char *)malloc(MAXSIZE * sizeof(char));
    memset(returnStr, 0, MAXSIZE * sizeof(char));
    returnStr[0] = '1';
    returnStr[1] = '\0';
    if (n == 1) {
        return returnStr;
    }
    char *tmpStrCpy = (char *)malloc(MAXSIZE * sizeof(char));
    memset(tmpStrCpy, 0, MAXSIZE * sizeof(char));

    char tmpChar;
    int tmpCharCount = 0;
    int tmpI;
    char tmpCharProcess[3];
    while(nCpy > 1) {
        memset(tmpStrCpy, 0, MAXSIZE * sizeof(char));
        for (i = 0; i < strlen(returnStr); i++) {
            tmpChar = returnStr[i];
            tmpCharCount = 1;
            tmpI = i + 1;
            if (tmpI > (strlen(returnStr) - 1)) {
                goto __END__;
            }
            while (tmpChar == returnStr[tmpI]) {

                tmpCharCount++;
                tmpI++;
                if (tmpI > (strlen(returnStr) - 1)) {
                    break;
                }
            }
            __END__:
            tmpCharProcess[0] = tmpCharCount + '0';
            tmpCharProcess[1] = tmpChar;
            tmpCharProcess[2] = '\0';    
            strcat(tmpStrCpy, tmpCharProcess);
            i = i + tmpCharCount - 1;
        }
        memcpy(returnStr, tmpStrCpy, strlen(tmpStrCpy) + 1);
        //printf("returnStr: %s\n", returnStr);
        nCpy--;
    }

}
    return returnStr;
```
