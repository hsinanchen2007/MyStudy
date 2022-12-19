```
char * multiply(char * num1, char * num2){
    int lenStr1 = strlen(num1);
    long long int value1 = 0;
    int lenStr2 = strlen(num2);
    long long int value2 = 0;
    long long int value = 0;
    int i;
    int count = 0;
    char *returnStr;

    for (i = 0; i < lenStr1; i++) {
        value1 = value1 * 10 + (num1[i] - '0');
    }
    for (i = 0; i < lenStr2; i++) {
        value2 = value2 * 10 + (num2[i] - '0');
    }
    value1 = value1 * value2;
    value = value1;

    if (value == 0) {
        returnStr = (char *)malloc(2 * sizeof(char));
        returnStr[0] = '0';
        returnStr[1] = '\0'; 
        return returnStr;
    }

    while (value1 != 0) {
        value1 = value1 / 10;
        count++;
    }
    printf("value: %lld, count: %d\n", value, count);

    returnStr = (char *)malloc((count + 1) * sizeof(char));
    for (i = 0; i < count; i++) {
        returnStr[count - 1 - i] = value % 10 + '0';
        value = value / 10;
    }
    returnStr[count] = '\0';
    return returnStr;
}
```
