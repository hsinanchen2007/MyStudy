/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char map[][5] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
int FillStr(char *digits,int index, int length, char *res, char ** result, int *count) {
    if (index == length + 1) {
        res[index] = '\0';
        strcpy(result[*count],res);
        (*count)++;
        return 0;
    }
    for (int i=0;i<strlen(map[digits[index] - '0']);i++) {
        
        res[index] = map[digits[index] - '0'][i];
        FillStr(digits,index + 1, length, res, result, count);
    }
    return 0;
}

char ** letterCombinations(char * digits, int* returnSize){
    
    
    int count[10] = {0};
    int length = strlen(digits);

    char *str = digits;
    *returnSize = 1;
    if (length == 0){
        *returnSize = 0;
        char **returnArray = (char **)malloc(sizeof(char *) * (*returnSize));
        return 0;
    }
    while(*str != '\0') {
        count[*str - '0']++;
        if (*str != '7' && *str != '9') {
            *returnSize *= 3; 
        } else {
            *returnSize *= 4; 
        }
        str++;
    }
    char **returnArray = (char **)malloc(sizeof(char *) * (*returnSize));
    for (int i=0;i<(*returnSize);i++){
        returnArray[i] = (char *)malloc(sizeof(char) * (length + 1));
    }
    str = digits;
    char tempStr[5] = "";
    int counta = 0;
    FillStr(digits, 0, length - 1,tempStr,returnArray, &counta);
    
    return returnArray;
}