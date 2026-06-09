### 解题思路
类似LeetCode括号生成那一题的回溯思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char set[10][4] = {{'0','0','0','0'}, {'0','0','0','0'}, {'a', 'b', 'c', '0'}, {'d', 'e', 'f', '0'}, {'g', 'h', 'i', '0'}, {'j', 'k', 'l', '0'}, {'m', 'n', 'o', '0'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v', '0'}, {'w', 'x', 'y', 'z'}};

void Add(char *str, char **ret, int *returnSize, char * digits, int index, int len){
    if(index == len){
        ret[*returnSize] = (char*)calloc(len + 1,sizeof(char));
        strcpy(ret[(*returnSize)++], str);
        return;
    }
    for(int i = 0; i < 3; i++){
        str[index] = set[digits[index] - '0'][i];
        Add(str, ret, returnSize, digits, index + 1, len);
    }
    if(digits[index] == '7' || digits[index] == '9'){
        str[index] = set[digits[index] - '0'][3];
        Add(str, ret, returnSize, digits, index + 1, len);
    }
}

char ** letterCombinations(char * digits, int* returnSize){
    int len = strlen(digits);
    *returnSize = 0;
    if(len == 0){
        return NULL;
    }
    char **ret = (char**)malloc(12000 * sizeof(char*));
    char *temp = (char*)calloc(len + 1,sizeof(char));
    Add(temp, ret, returnSize, digits, 0, len);
    return ret;
}
```