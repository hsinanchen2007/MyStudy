char ** letterCombinations(char * digits, int* returnSize){
    *returnSize = 0;
    if (digits[0] == '\0') {
        return NULL;
    }
    int MAX_NUM_LEN = 1000;
    char* numTostr[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    char* Queue[MAX_NUM_LEN];
    int begin = 0, end = 0;
    int i;
    Queue[end] = (char*)malloc(sizeof(char) * MAX_NUM_LEN);
    Queue[end++][0] = '\0';

    for (i = 0; digits[i] != '\0'; i++) {
        int queuePosition = 0;
        int index = digits[i] - '2';
        int tmpEnd = end;
        for (queuePosition = begin; queuePosition < tmpEnd; queuePosition++) {
            int strPosition = 0;
            for (strPosition = 0; numTostr[index][strPosition] != '\0'; strPosition++) {
                char tmpStr[2] = {numTostr[index][strPosition], '\0'};
                Queue[end] = (char*)malloc(sizeof(char) * MAX_NUM_LEN);
                Queue[end][0] = '\0';
                strcat(Queue[end], Queue[queuePosition]);
                strcat(Queue[end++], tmpStr);
            }
        }
        begin = tmpEnd;
    }

    char** strArr = (char**)malloc(sizeof(char*) * (end - begin));
    for (i = begin; i < end; i++) {
        strArr[i-begin] = (char*)malloc(sizeof(char) * MAX_NUM_LEN);
        strcpy(strArr[i-begin], Queue[i]);
    }

    *returnSize = end - begin;
    return strArr;
}
