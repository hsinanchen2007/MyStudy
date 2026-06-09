C语言的解答，基于回溯法，比起C++,C语言字符串处理还是太麻烦。
```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
const char *str[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

char ** backTracking(char * digits, int* returnSize)
{
    int index = (*digits) - '0';
    if (strlen(digits + 1) == 0) {
        char ** ret = (char **)malloc(sizeof(char*) * strlen(str[index]));
        for (int i = 0; i < strlen(str[index]); ++i) {
            ret[i] = (char *)malloc(sizeof(char) * 2);
            ret[i][0] = str[index][i];
            ret[i][1] = '\0';
        }
        *returnSize = strlen(str[index]);    //字符串数组的长度
        return ret;
    } else {
        char ** tmp = backTracking(digits + 1, returnSize);
        char ** ret = (char **)malloc(sizeof(char*) * (*returnSize) * strlen(str[index]));
        int tmpSize = strlen(tmp[0]);
        for (int i = 0; i < strlen(str[index]); ++i) {
            int start = (*returnSize) * i;
            for (int j = 0; j < (*returnSize); ++j) {
                ret[start + j] = (char *)malloc(sizeof(char) * (tmpSize + 2));
                ret[start + j][tmpSize + 1] = '\0';
                strcpy(ret[start + j] + 1, tmp[j]);
                ret[start + j][0] = str[index][i];
                //strcpy(ret[start + j], tmp[j]);                   //此为逆序输出字符串，不符合
                //ret[start + j][tmpSize] = str[index][i];          //["da","ea","fa","db","eb","fb","dc","ec","fc"]
            }
        }
        *returnSize = (*returnSize) * strlen(str[index]);   //记得更新返回字符串数组大小，否则输出异常
        return ret;
    }
}

char ** letterCombinations(char * digits, int* returnSize){
    if (strlen(digits) == 0) {
        *returnSize = 0;
        return NULL;
    }
    return backTracking(digits, returnSize);
# }
```
