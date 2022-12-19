### 解题思路
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
说明：

所有输入均为小写字母。
不考虑答案输出的顺序。



malloc的内存大小尽量用入参，　栈变量才用固定大小；　否则内存也会超出限制

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 int cmp(void * a, void * b) {
     return *(char *)a - *(char *)b;
 }

#define LEN  10000
#define SIZE 24
char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    char temp[SIZE] = {0};
    char dict[LEN][SIZE] = {0};
    int i, j, k = 0;
    char ***res = malloc(strsSize * sizeof(char *));
    *returnColumnSizes = malloc(strsSize * sizeof(int));

    memset(*returnColumnSizes, 0 , strsSize * sizeof(int));
    for (i = 0; i < strsSize; i++) {
        strcpy(temp, strs[i]);
        qsort(temp, strlen(temp), 1, cmp);

        for (j = 0; j < k; j++) {
            if (!strcmp(temp, dict[j])) {
                res[j][(*returnColumnSizes)[j]] = strs[i];
                (*returnColumnSizes)[j] += 1;
                break;
            }
        }

        if (j == k) {
            strcpy(dict[k], temp);
            res[k] = malloc(8*sizeof(char *));
            res[k][(*returnColumnSizes)[k]] = strs[i];
            (*returnColumnSizes)[k] += 1;
            k++;
        }
    }
 
    *returnSize = k;
    return res;
}
```