### 解题思路
![17.PNG](https://pic.leetcode-cn.com/b1902da0370197e1cdcd6de739bfe4e865b35f10449fda07cb1a20c1a7d57ca1-17.PNG)


### 代码

```c
void DFS(char** table, int *tableSize, char* digits, int digitsLen, char* str, int index, char** rst, int *rstSize)
{
    // termination
    if (index == digitsLen) {
        strcpy(rst[*rstSize], str);
        *rstSize = *rstSize + 1;
        return;
    }

    // process
    char d = digits[index];
    int i = d - '2';
    for (int j = 0; j < tableSize[i]; j++) {
        str[index] = table[i][j];
        str[index + 1] = '\0';
        DFS(table, tableSize, digits, digitsLen, str, index + 1, rst, rstSize);
    }
    // drill down

    // clear up states
}

char** letterCombinations(char* digits, int* returnSize)
{
    *returnSize = 0;
    char** table = (char**)calloc(8, sizeof(char*));
    int tableSize[8] = {3, 3, 3, 3, 3, 4, 3, 4};
    char c = 'a';
    for (int i = 0; i < 8; i++) {
        table[i] = (char*)calloc(tableSize[i], sizeof(char));
        for (int j = 0; j < tableSize[i]; j++) {
            table[i][j] = c;
            c = c + 1;
        }
    }
    int n = strlen(digits);
    if (n == 0) {
        return NULL;
    }
    int totalSize = 1;
    for (int i = 0; i < n; i++) {
        int nums = tableSize[(digits[i] - '2')];
        totalSize = totalSize * nums;
    }
    *returnSize = totalSize;
    char** rst = (char**)calloc(totalSize, sizeof(char*));
    for (int i = 0; i < *returnSize; i++) {
        rst[i] = (char*)calloc(n + 1, sizeof(char));
    }

    char* str = (char*)calloc(n + 1, sizeof(char));
    int rstSize = 0;
    DFS(table, tableSize, digits, n, str, 0, rst, &rstSize);
    return rst;
}

```