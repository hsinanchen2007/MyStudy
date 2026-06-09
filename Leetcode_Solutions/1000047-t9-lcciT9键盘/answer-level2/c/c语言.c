### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_NUM 1024
char** getValidT9Words(char* num, char** words, int wordsSize, int* returnSize){
    char *letter[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    char **res = (char **)malloc(sizeof(char *) * MAX_NUM);
    int resCnt = 0;
    for (int i = 0; i < wordsSize; i++) {
        int count = 0;
        for (int j = 0; j < strlen(words[i]); j++) {
            char *tem = letter[num[j] - '0'];
            if (strchr(tem, words[i][j]) != NULL) {
                count++;
            }
        }
        if (count == strlen(words[i])) {
            res[resCnt++] = words[i];
        }
    }
    *returnSize = resCnt;
    return res;
}
```