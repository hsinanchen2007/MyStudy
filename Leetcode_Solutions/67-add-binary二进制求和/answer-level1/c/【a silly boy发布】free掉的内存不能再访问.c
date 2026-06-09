![F431E761-3590-47C4-8F19-4B71C691756D.jpeg](https://pic.leetcode-cn.com/d1790cb0f234fcdceb735ed8c58678560d983981bee6532c496a31e03a81aa89-F431E761-3590-47C4-8F19-4B71C691756D.jpeg)

```

void SubFunc(char *a, char *b, char *returnStr1, char *returnStr2, int *flag)
{
    char tmpChar = '0';
    int i;
    int lenA = strlen(a);
    int lenB = strlen(b);
    int maxSum = lenA > lenB ? lenA : lenB;
    for (i = lenA - 1; i >= lenA - lenB; i--) {
        if ((a[i] == '1') && (b[i - (lenA - lenB)] == '1')) {
            returnStr1[i] = tmpChar;
            tmpChar = '1';
        } else {
            if ((a[i] == '1') || (b[i - (lenA - lenB)] == '1')) {
                if (tmpChar == '1') {
                    tmpChar = '1';
                    returnStr1[i] = '0';
                } else {
                    tmpChar = '0';
                    returnStr1[i] = '1'; 
                }
            } else {
                returnStr1[i] = tmpChar;   
                tmpChar = '0';
            }
        }
    }
    for (i = lenA - lenB - 1; i >= 0; i--) {
        if (tmpChar == '0') {
            returnStr1[i] = a[i];
        } else {
            if ((a[i] == '1') && (tmpChar == '1')) {
                tmpChar = '1';
                returnStr1[i] = '0';
            } else {
                tmpChar = '0';
                returnStr1[i] = '1';      
            }
        }
    }
    if (tmpChar == '1') {
        returnStr2[0] = tmpChar;
        memcpy(&returnStr2[1], returnStr1, (maxSum) * sizeof(char));
        returnStr2[maxSum + 1] = '\0';
        free(returnStr1);
        returnStr1 = NULL;
        *flag = 2;
    } else {
        free(returnStr2);
        returnStr1[maxSum] = '\0';
        returnStr2 = NULL;
        *flag = 1;
    }
}

char * addBinary(char * a, char * b)
{
    int lenA = strlen(a);
    int lenB = strlen(b);
    if (lenA == 0) {
        return b;
    }
    if (lenB == 0) {
        return a;
    }
    int maxSum = lenA > lenB ? lenA : lenB;
    char *returnStr1 = (char *)malloc((maxSum + 1) * sizeof(char));
    char *returnStr2 = (char *)malloc((maxSum + 1 + 1) * sizeof(char));
    int flag = 0;
    if (lenA >= lenB) {
        SubFunc(a, b, returnStr1, returnStr2, &flag);
    } else {
        SubFunc(b, a, returnStr1, returnStr2, &flag);  
    }
    //printf("returnStr1: %s\n", returnStr1);
    //printf("returnStr2: %s\n", returnStr2);
    
    if (flag == 2) {
        return returnStr2;
    } else {
        return returnStr1;
    }
    
    return NULL;
}
```
