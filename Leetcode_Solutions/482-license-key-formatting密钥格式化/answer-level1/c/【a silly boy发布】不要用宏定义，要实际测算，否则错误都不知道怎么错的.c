![13A9F2EA-7765-415F-96F8-7D35EB0B8CE2.jpeg](https://pic.leetcode-cn.com/dc2396adacb8e4997e0de06460f13597c6af2633330f39fd64a277f81aa850a8-13A9F2EA-7765-415F-96F8-7D35EB0B8CE2.jpeg)

```
#define MAXSIZE 12001

char * licenseKeyFormatting(char * S, int K){
    int lenS = strlen(S);
    int tmpK = 0;
    char *changeStr;
    int changeStrIndex = 0;
    char *returnStr;
    int returnStrIndex = 0;
    int i;
    int changeStrSize = 0;
    if ((S == NULL) || (lenS == 0)) {
        return "";
    }
    for (i = 0; i < lenS; i++) {
        if (S[i] != '-') {
            changeStrSize++;
        }
    }
    
    if (changeStrSize == 0) {

        return "";
    }
    changeStr = (char *)malloc(changeStrSize * sizeof(char));
    for (i = 0; i < lenS; i++) {
        if (S[i] != '-') {
            changeStr[changeStrIndex] = (S[i] < 'a' || S[i] > 'z') ? S[i] : S[i] - ('a' - 'A');
            changeStrIndex++;
        }
    }
    //changeStr[changeStrIndex] = '\0';

    int yu = changeStrIndex % K;
    int returnStrSize = changeStrIndex + changeStrIndex / K;
    returnStr = (char *)malloc((returnStrSize + 1) * sizeof(char));

    for (i = 0; i < yu; i++) {
        returnStr[returnStrIndex] = changeStr[i];
        returnStrIndex++;
    }
    if (yu != 0) {
        returnStr[returnStrIndex] = '-';
        returnStrIndex++;
    }

    int tmpIndex = 0;
    for (i = yu; i < changeStrIndex; i++) {
        returnStr[returnStrIndex] = changeStr[i];
        returnStrIndex++;
        tmpIndex++;
        if (tmpIndex == K) {
            tmpIndex = 0;
            returnStr[returnStrIndex] = '-';
            returnStrIndex++;
        }
    }
    if (returnStr[returnStrIndex - 1] == '-') {
        returnStr[returnStrIndex - 1] = '\0';
    } else {
        returnStr[returnStrIndex] = '\0';
    }
    free(changeStr);
    return returnStr;
}
```
