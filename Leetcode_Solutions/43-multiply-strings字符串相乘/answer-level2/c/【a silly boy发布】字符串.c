```
#define NUM_10 10

bool StartDeal(char * num1, char * num2)
{
    if ((num1 == NULL) || (num2 == NULL)) {
        return true;
    }
    int lenS1 = strlen(num1);
    int lenS2 = strlen(num2);
    if ((lenS1 == 0) || (lenS2 == 0)) {
        return true;
    }

    return false;
}

void RebuildData(char * num1, char * num2, char *returnStr, int *returnStrIndex, int *num)
{
    int i;
    int lenS1 = strlen(num1);
    int lenS2 = strlen(num2);
    for (i = 0; i < lenS1 + lenS2; i++) {
        if (((*returnStrIndex == 0)) && (num[i] == 0)) {
            continue;
        }
        returnStr[(*returnStrIndex)] = num[i] + '0';
        (*returnStrIndex)++;
    }

    if ((*returnStrIndex) == 0) {
        returnStr[(*returnStrIndex)] = '0';
        (*returnStrIndex)++;
    }
    returnStr[(*returnStrIndex)] = '\0';
}

char * multiply(char * num1, char * num2)
{
    bool isTrue;
    isTrue = StartDeal(num1, num2);
    if (isTrue == true) {
        return "";
    }
    int lenS1 = strlen(num1);
    int lenS2 = strlen(num2);
    int *num = (int *)malloc((lenS1 + lenS2) * sizeof(int));
    memset(num, 0, (lenS1 + lenS2) * sizeof(int));

    int i;
    int j;
    for (i = lenS1 - 1; i >= 0; i--) {
        for (j = lenS2 - 1; j >= 0; j--) {
            num[i + j] += (num1[i] - '0') * (num2[j] - '0');
        }
    }

    for (i = lenS1 + lenS2 - 1; i > 0; i--) {
        num[i] = num[i - 1];
    }
    num[0] = 0;

    int tmpDiv = 0;
    int tmpRema;
    for (i = (lenS1 + lenS2 - 1); i > 0; i--) {
        tmpRema = (num[i] + tmpDiv) % NUM_10;
        tmpDiv = (num[i] + tmpDiv) / NUM_10;
        num[i] = tmpRema;
    }
    num[0] = tmpDiv;

    char *returnStr = (char *)malloc((lenS1 + lenS2 + 1) * sizeof(char));
    int returnStrIndex = 0;
    RebuildData(num1, num2, returnStr, &returnStrIndex, num);

    free(num);
    return returnStr;
}
```
