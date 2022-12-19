### 解题思路
此处撰写解题思路
暴力解法，将 2-9 数字用一个二维数组全部包括起来，然后递归逐步解题。
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
const char g_numbers[8][5] = {
    "abc", "def", "ghi", "jkl", "mno", "pqrs",
    "tuv", "wxyz"
};
int getCharSize(char digit)
{
     if (digit == '7' || digit == '9') {
         return 4;
     }
     return 3;
}
void fillRes(char **res, const char *digits, int *returnSize, int flag, char *path) {
    int charSize = strlen(digits);
    int charIndex = digits[flag] - '2';
    char *charArray = g_numbers[charIndex]; 
    int thisCharlen = getCharSize(digits[flag]);
    //printf("check fill:%d,%d,%d,%d,%c\n", charIndex, charSize, flag, thisCharlen, digits[flag]);
    //printf("char array:%s\n", charArray);
    if (flag == (charSize - 1)) {
        // end data;
        for (int i = 0; i < thisCharlen; i++) {
            char *finalPath = (char *)malloc(sizeof(char) * (charSize + 1));
            memset(finalPath, 0, sizeof(char) * (charSize + 1));
            path[flag] = charArray[i];
            memcpy(finalPath, path, sizeof(char) * (charSize + 1));
            res[(*returnSize)] = finalPath;
            //printf("returnSize:%d, %d\n", (*returnSize), i);
            //printf("add res:%s\n", res[(*returnSize)]);            
            (*returnSize)++;
        }
        return;
    }
    for (int i = 0; i < thisCharlen; i++) {        
        path[flag] = charArray[i];
        fillRes(res, digits, returnSize, flag + 1, path);
    }

}

char ** letterCombinations(char * digits, int* returnSize){
    int charSize = strlen(digits);
    (*returnSize) = 0;
    if (charSize <= 0) {                
        return NULL;
    }


    int resLen = pow(4, charSize);
    char **res = (char **)malloc(sizeof(char *) * (resLen + 1));
    memset(res, 0, sizeof(char *) * resLen);
    char *path = (char *)malloc(sizeof(char) * (charSize + 1));
    memset(path, 0, sizeof(char) * (charSize + 1));
    //printf("check res basic:%d,%d\n", resLen, charSize);
    fillRes(res, digits, returnSize, 0, path);
    //printf("check final res basic:%d,%d, %d\n", resLen, charSize, (*returnSize));
    return res;
}
```