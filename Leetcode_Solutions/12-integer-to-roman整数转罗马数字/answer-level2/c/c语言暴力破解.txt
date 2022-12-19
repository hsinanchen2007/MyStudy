void getRoman(int num, char smallNum, char midNum, char bigNum, char* retStr){
    char tmpStr[1000];
    int i = 0;
    if (0 < num && num < 4) {
        for (i = 0; i < num; i++) {
            tmpStr[i] = smallNum;
        }
    } else if (num == 4) {
        tmpStr[i++] = smallNum;
        tmpStr[i++] = midNum;
    } else if (4 < num && num < 9) {
        tmpStr[i++] = midNum;
        num = num - 5; 
        int j;
        for (j = 0; j < num; j++) {
            tmpStr[i++] = smallNum;
        }
    } else if (num == 9) {
        tmpStr[i++] = smallNum;
        tmpStr[i++] = bigNum;
    } else if (num == 10) {
        tmpStr[i++] = bigNum;
    }
    tmpStr[i] = '\0';
    strcat(retStr, tmpStr);
}
char * intToRoman(int num){
    char* retStr = (char*)malloc(sizeof(char) * 1000);
    memset(retStr, '\0', 1000);
    int Stack[1000];
    int top = -1;
    int iPosition = 1;
    int tmpNum = num;
    while (tmpNum != 0) {
        Stack[++top] = (tmpNum % 10) * iPosition;
        tmpNum = tmpNum / 10;
        iPosition *= 10;
    }

    int i;
    for (i = top; i >= 0; i--) {
        if (Stack[i] > 1000 && Stack[i] <= 3999) {
            getRoman(Stack[i] / 1000, 'M', 'M', 'M', retStr);
        } else if (Stack[i] > 100 && Stack[i] <= 1000){
            getRoman(Stack[i] / 100, 'C', 'D', 'M', retStr);
        } else if (Stack[i] > 10 && Stack[i] <= 100) {
            getRoman(Stack[i] / 10, 'X', 'L', 'C', retStr);
        } else if (Stack[i] >= 1 && Stack[i] <= 10) {
            getRoman(Stack[i], 'I', 'V', 'X', retStr);
        }
    }

    return retStr;
}