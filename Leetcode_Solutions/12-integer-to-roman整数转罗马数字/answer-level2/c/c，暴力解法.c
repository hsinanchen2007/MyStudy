c，暴力解法的
/*
1. 申请哈希表（三维指针）, hashTable[i][j]表示第i位、数字为j对应的罗马数字
2. 定义数据栈，存储十进制数对应的各个数值
3. 依次出栈，出栈数字对应的哈希表中的值依次拼接到返回值中
*/

char * intToRoman(int num){
    if (num < 1 || num > 3999) {
        return NULL;
    }
    // 定义一个哈希表存储对应数值对应的罗马数字
    char*** hashTable = (char***)malloc(sizeof(char**) * 4);
    for (int i = 0; i < 4; i++) {
        hashTable[i] = (char**)malloc(sizeof(char*) * 10);
        for (int j = 0; j < 10; j++) {
            hashTable[i][j] = (char*)malloc(sizeof(char) * 5);
        }
    }
    strcpy(hashTable[0][0], "");
    strcpy(hashTable[0][1], "I");
    strcpy(hashTable[0][2], "II");
    strcpy(hashTable[0][3], "III");
    strcpy(hashTable[0][4], "IV");
    strcpy(hashTable[0][5], "V");
    strcpy(hashTable[0][6], "VI");
    strcpy(hashTable[0][7], "VII");
    strcpy(hashTable[0][8], "VIII");
    strcpy(hashTable[0][9], "IX");

    strcpy(hashTable[1][0], "");
    strcpy(hashTable[1][1], "X");
    strcpy(hashTable[1][2], "XX");
    strcpy(hashTable[1][3], "XXX");
    strcpy(hashTable[1][4], "XL");
    strcpy(hashTable[1][5], "L");
    strcpy(hashTable[1][6], "LX");
    strcpy(hashTable[1][7], "LXX");
    strcpy(hashTable[1][8], "LXXX");
    strcpy(hashTable[1][9], "XC");

    strcpy(hashTable[2][0], "");
    strcpy(hashTable[2][1], "C");
    strcpy(hashTable[2][2], "CC");
    strcpy(hashTable[2][3], "CCC");
    strcpy(hashTable[2][4], "CD");
    strcpy(hashTable[2][5], "D");
    strcpy(hashTable[2][6], "DC");
    strcpy(hashTable[2][7], "DCC");
    strcpy(hashTable[2][8], "DCCC");
    strcpy(hashTable[2][9], "CM");

    strcpy(hashTable[3][0], "");
    strcpy(hashTable[3][1], "M");
    strcpy(hashTable[3][2], "MM");
    strcpy(hashTable[3][3], "MMM");
    strcpy(hashTable[3][4], "");
    strcpy(hashTable[3][5], "");
    strcpy(hashTable[3][6], "");
    strcpy(hashTable[3][7], "");
    strcpy(hashTable[3][8], "");
    strcpy(hashTable[3][9], "");

    int dataStack[10] = {0}; // 栈存储每个位上的数字
    int top = -1;
    char* returnArray = (char*)malloc(sizeof(char) * 20);
    returnArray[0] = '\0';
    if (returnArray == NULL) {
        return NULL;
    }
    while (num != 0) {
        // printf("%d  ", top);
        dataStack[++top] = num % 10; // 数值入栈
        num = num / 10;
    }
    while (top != -1) {
        strcat(returnArray, hashTable[top][dataStack[top]]);
        top--;
    }
    // 释放申请哈希内存
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 10; j++) {
            free(hashTable[i][j]);
        }
        free(hashTable[i]);
    }
    free(hashTable);
    return returnArray;
}