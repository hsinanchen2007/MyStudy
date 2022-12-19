

 const char g_table[10][5] = {
     {},       //0
     {"!@#"},  //1
     {"abc"},  //2
     {"def"},  //3
     {"ghi"},  //4
     {"jkl"},  //5
     {"mno"},  //6
     {"pqrs"}, //7
     {"tuv"},  //8
     {"wxyz"}, //9
 };

#define MAX_LEN  1024
char temp[MAX_LEN] = {0};

void DFS(char *digits, int index, char **result, int *totalSize) {
    int len = strlen(digits);
    
    if (index == len) {
        memcpy(result[*totalSize], temp, sizeof(char) * (len + 1));
        //printf("%d:%s\n", *totalSize, temp);
        (*totalSize)++;
        return;
    }
    int curDigit = digits[index] - '0';   
    for (int j = 0; j < strlen(g_table[curDigit]);j++) {
        temp[index] = g_table[curDigit][j];
        DFS(digits, index + 1, result, totalSize);
    }
    return;

}
char ** letterCombinations(char * digits, int* returnSize){
    *returnSize = 0;
    if (digits == NULL) {
        return NULL;
    }
    int len = strlen(digits);
    if (len == 0) {
        return NULL;
    }
    memset(temp, 0, sizeof(char) * MAX_LEN);
    
    int count = 1 << (2 * len); //max count = 4^n
    char **ans = (char**)malloc(sizeof(char*) * (count + 1));
    for (int i = 0; i < count; i++) {
        ans[i] = (char*)calloc(5, sizeof(char));
    }
    
    DFS(digits, 0, ans, returnSize);
    return ans;
}