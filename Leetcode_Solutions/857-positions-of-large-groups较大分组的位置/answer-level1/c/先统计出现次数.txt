### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define LEN 1000
int** largeGroupPositions(char * S, int* returnSize, int** returnColumnSizes){

    int count[26] = {0};
    for (int i = 0; i < strlen(S); i++) {
        count[S[i] - 'a']++;
    }
    int **ans;
    int return_size = 0;
    ans = (int **)malloc(sizeof(int *) * LEN);
    *returnColumnSizes = (int *)malloc(sizeof(int) * LEN);
    
    if (strlen(S) == 0) {
        *returnSize = 0;
        (*returnColumnSizes)[return_size] = 0;
    }
    int start = 0;
    int end = 0;
    
    int i = 0;
    while (i < strlen(S)) {
        if (count[S[i] - 'a'] >= 3) {
            //printf("%c,id:%d\n", S[i], i);
            start = i;
            while (S[start] == S[i] && i < strlen(S)) {
               i++;
            }
            if (i - start >= 3) {
                end = i - 1;
                ans[return_size] = (int *)malloc(sizeof(int) * 2);
                (*returnColumnSizes)[return_size] = 2;
                ans[return_size][0] = start;
                ans[return_size][1] = end;
                return_size++;
            }
        } else {
            i++;
        }
    }
    *returnSize = return_size;
    return ans;
}
```