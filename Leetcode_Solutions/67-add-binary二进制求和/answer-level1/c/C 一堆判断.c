### 解题思路
先把两个字符串放到两个数组中，从低位到高位。
计算和
进位计算
翻转后放到字符数组中

### 代码

```c
char * addBinary(char * a, char * b){
    //申请数组装 字符串的数字
    int aLength = strlen(a);
    int bLength = strlen(b);

    int * aArray = (int *)malloc(aLength * sizeof(int));
    memset(aArray, 0, aLength * sizeof(int));

    int * bArray = (int *)malloc(bLength * sizeof(int));
    memset(bArray, 0, bLength * sizeof(int));

    for (int i = strlen(a) - 1; i >= 0; i--) {
        if (*(a + i) == '1') {
            *(aArray + aLength - i - 1) = 1;
        } else {
            *(aArray + aLength - i - 1) = 0;
        }
    }

     for (int i = strlen(b) - 1; i >= 0; i--) {
        if (*(b + i) == '1') {
            *(bArray + bLength - i - 1) = 1;
        } else {
            *(bArray + bLength - i - 1) = 0;
        }
    }

    int maxLength = 0;
    int flag = 0;
    if (aLength > bLength) {
        maxLength = aLength + 1;  //假设需要进位
        flag = 0;
    } else {
        maxLength = bLength + 1;  //假设需要进位
        flag = 1;
    }
    int* cArray = (int*)malloc(maxLength * sizeof(int));
    memset(cArray, 0, maxLength * sizeof(int));

    int zeroFlag = 0;
    if (flag == 0) {
        //a比较长
        for (int i = 0; i < aLength; i++) {
           cArray[i] = aArray[i];
        }
        for (int i = 0; i < bLength; i++) {
           cArray[i] = aArray[i] + bArray[i];
        }
    } else {
        //b比较长
         for (int i = 0; i < bLength; i++) {
           cArray[i] = bArray[i];
        }
        for (int i = 0; i < aLength; i++) {
           cArray[i] = aArray[i] + bArray[i];
        }
    }

    for (int i = 0; i < maxLength; i++) {
        if ((cArray[i] == 0) || (cArray[i] == 1)) {
            continue;
        } else if (cArray[i] == 2) {
            cArray[i + 1]++;
            cArray[i] = 0;
        } else {
            cArray[i + 1]++;
            cArray[i] = 1;
        }
    }

    int charLength = 0;
    if (cArray[maxLength - 1] > 0) {
        charLength = maxLength + 1;
    } else {
        charLength = maxLength;
    }

    //申请一块内存封装输出
    char * returnArray = (char *)malloc(charLength * sizeof(char));
    memset(returnArray, '\0', charLength * sizeof(char));

    for (int i = 0; i < charLength - 1; i++) {
        returnArray[i] = cArray[charLength - i - 2] + 48;
    }
    free(aArray);
    free(bArray);
    free(cArray);
    return returnArray;
}
```