```
char * addStrings(char * num1, char * num2){
    int i;
    int j;
    int lenStr1 = strlen(num1);
    int lenStr2 = strlen(num2);
    int lenBet = lenStr1 > lenStr2 ? lenStr1 - lenStr2 : lenStr2 - lenStr1;
    int lenReturnStrSize = lenStr1 >= lenStr2 ? lenStr1 : lenStr2;
    char *returnStr1 =  (char *)malloc((lenReturnStrSize + 1) * sizeof(char));
    char *returnStr2 =  (char *)malloc((lenReturnStrSize + 2) * sizeof(char));
    int addFlag = 0;
    int tmpValue = 0;

    if (num1 == NULL) {
        return num2;
    }
    if (num2 == NULL) {
        return num1;
    }

    //printf("lenStr1: %u, lenStr2: %u\n", lenStr1, lenStr2);
    if (lenStr1 > lenStr2) {
        for (i = lenStr1 - 1; i >= lenBet; i--) {
            tmpValue = ((num1[i] - '0') + (num2[i - lenBet] - '0') + addFlag);
            if (tmpValue >= 10) {
                returnStr1[i] = tmpValue % 10 + '0';
                addFlag = 1;
            } else {
                returnStr1[i] = tmpValue + '0';
                addFlag = 0;
            }
            //printf("%c", returnStr1[i]);
        }
        //printf("\n");
        for (i = lenBet - 1; i > 0; i--) {
            tmpValue = ((num1[i] - '0') + addFlag);
            if (tmpValue >= 10) {
                returnStr1[i] = tmpValue % 10 + '0';
                addFlag = 1;
            } else {
                returnStr1[i] = tmpValue + '0';
                addFlag = 0;
            }
            //printf("%c", returnStr1[i]);
        }
        tmpValue = ((num1[0] - '0') + addFlag);
        //printf("tmpValue: %u\n", tmpValue);
        if (tmpValue >= 10) {
            returnStr1[0] = tmpValue % 10 + '0';
            returnStr2[0] = tmpValue / 10 + '0';
            for (i = 0; i < lenStr1; i++) {
                returnStr2[i + 1] = returnStr1[i];
            }
            returnStr2[lenReturnStrSize + 1] = '\0';
            free(returnStr1);
            return returnStr2;
        } else {
            returnStr1[0] = tmpValue  + '0';
            returnStr1[lenStr1] = '\0';
            free(returnStr2);
            return returnStr1;
        }
    } else if (lenStr1 < lenStr2) {
        for (i = lenStr2 - 1; i >= lenBet; i--) {
            tmpValue = ((num2[i] - '0') + (num1[i - lenBet] - '0') + addFlag);
            if (tmpValue >= 10) {
                returnStr1[i] = tmpValue % 10 + '0';
                addFlag = 1;
            } else {
                returnStr1[i] = tmpValue + '0';
                addFlag = 0;
            }
            //printf("%c", returnStr1[i]);
        }
        //printf("\n");
        for (i = lenBet - 1; i > 0; i--) {
            tmpValue = ((num2[i] - '0') + addFlag);
            if (tmpValue >= 10) {
                returnStr1[i] = tmpValue % 10 + '0';
                addFlag = 1;
            } else {
                returnStr1[i] = tmpValue + '0';
                addFlag = 0;
            }
            //printf("%c", returnStr1[i]);
        }
        tmpValue = ((num2[0] - '0') + addFlag);
        //printf("tmpValue: %u\n", tmpValue);
        if (tmpValue >= 10) {
            returnStr1[0] = tmpValue % 10 + '0';
            returnStr2[0] = tmpValue / 10 + '0';
            for (i = 0; i < lenStr2; i++) {
                returnStr2[i + 1] = returnStr1[i];
            }
            returnStr2[lenReturnStrSize + 1] = '\0';
            free(returnStr1);
            return returnStr2;
        } else {
            returnStr1[0] = tmpValue  + '0';
            returnStr1[lenStr2] = '\0';
            free(returnStr2);
            return returnStr1;
        }
    } else {
        for (i = lenStr1 - 1; i >= 0; i--) {
            tmpValue = ((num1[i] - '0') + (num2[i] - '0') + addFlag);
            if (tmpValue >= 10) {
                returnStr1[i] = tmpValue % 10 + '0';
                addFlag = 1;
            } else {
                returnStr1[i] = tmpValue + '0';
                addFlag = 0;
            }
            //printf("%c", returnStr1[i]);
        }

        //printf("tmpValue: %u\n", tmpValue);
        if (tmpValue >= 10) {
            returnStr1[0] = tmpValue % 10 + '0';
            returnStr2[0] = tmpValue / 10 + '0';
            for (i = 0; i < lenStr1; i++) {
                returnStr2[i + 1] = returnStr1[i];
            }
            returnStr2[lenReturnStrSize + 1] = '\0';
            free(returnStr1);
            return returnStr2;
        } else {
            returnStr1[0] = tmpValue  + '0';
            returnStr1[lenStr1] = '\0';
            free(returnStr2);
            return returnStr1;
        }
    }
}
```
