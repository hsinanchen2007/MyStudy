![image.png](https://pic.leetcode-cn.com/cb42c7044ca829db08f1dafbe6b4888aa49c62fc86595d9fdd3c7d3bc17487e6-image.png)
```
#define MAXSIZE (50000 * 2)

int SumCnt(int a)
{
    int tmpVal = 0;
    int tmpCnt = 0;

    while (a != 0) {
        tmpVal = a % 10;
        a = a / 10;
        tmpCnt++;
    }

    return tmpCnt;
}

char* compressString(char* S){
    int lenS = strlen(S);
    char *returnStr = (char *)malloc((MAXSIZE + 1) * sizeof(char));
    int returnStrIndex = 0;
    int index = 1;
    int i;

    if (S == NULL) {
        return NULL;
    }

    char tmpC = S[0];
    int tmpVal = 0;
    int tmpCnt = 0;
    int tmpCntCpy = 0;
    int indexCpy = 0;

    for (i = 1; i < lenS; i++) {
        if (tmpC == S[i]) {
            index++;
        } else {
            returnStr[returnStrIndex] = tmpC;
            returnStrIndex++;

            if (index < 10) {
                returnStr[returnStrIndex] = index + '0';
                returnStrIndex++;
            } else {
                tmpCnt = SumCnt(index);
                //printf("tmpCnt: %d\n", tmpCnt);
                tmpCntCpy = tmpCnt;
                tmpCnt--;
                while (index != 0) {
                    tmpVal = index % 10;
                    //printf("tmpVal: %d. tmpCnt: %d\n", tmpVal, tmpCnt);
                    index = index / 10;
                    returnStr[returnStrIndex + tmpCnt] = tmpVal + '0';
                    tmpCnt--;
                }
                returnStrIndex = returnStrIndex + tmpCntCpy;
            }
            tmpC = S[i];
            index = 1;
        }
    }
    returnStr[returnStrIndex] = tmpC;
    returnStrIndex++;


    if (index < 10) {
        returnStr[returnStrIndex] = index + '0';
    } else {
        tmpCnt = SumCnt(index);
        tmpCnt--;
        tmpCntCpy = tmpCnt;
        while (index != 0) {
            tmpVal = index % 10;
            index = index / 10;
            returnStr[returnStrIndex + tmpCnt] = tmpVal + '0';
            tmpCnt--;
        }
        returnStrIndex = returnStrIndex + tmpCntCpy;
    }
 

    if (returnStrIndex + 1 >= lenS) {
        return S;
    }

    returnStrIndex++;
    returnStr[returnStrIndex] = '\0';

    return returnStr;
}
```
