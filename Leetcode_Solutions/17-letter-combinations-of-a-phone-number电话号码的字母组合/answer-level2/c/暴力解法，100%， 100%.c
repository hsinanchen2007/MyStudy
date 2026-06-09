### 解题思路
还没学到大家说的dfs的部分，第一反应暴力分情况解，可能做的人少吧，执行时间0ms，100%, 100%。我还是好好去学数据结构吧。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


char ** letterCombinations(char * digits, int* returnSize){
    int  i = strlen(digits)-1, len = 0, size = 1, j;
    char num_char[8][5] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int  num_num[8] = {3,3,3,3,3,4,3,4}, *tmp=NULL;
    char **ans=NULL;

    tmp = (int*)malloc(sizeof(int)*strlen(digits));

    if (digits == NULL || digits[0] == '\0') {
        *returnSize = 0;
        return NULL;
    }
    
    while( i >= 0) {
        size *= num_num[digits[i]-'2'];
        tmp[i] = size;
        i--;
    }

    ans = (char**) malloc( sizeof(char*) * size);
    for(i = 0; i < size; i++) {
        ans[i] = (char*)malloc( sizeof(char) * (strlen(digits)+1) );
        ans[i][strlen(digits)] = '\0';
    }
    
    if (strlen(digits) == 1) {
        for (j = 0; j < num_num[digits[0]-'2']; j++) 
            ans[j][0] = num_char[digits[0]-'2'][j];
    }

    else {
        for (len = 0; len<size; len++) {
            for (i = 0; i < strlen(digits); i++) {
                for (j = 0; j < num_num[digits[i]-'2']; j++) {
                    if (i == 0 && len/tmp[i+1] == j)
                        ans[len][i] = num_char[digits[i]-'2'][j];
                    if ( (i == (strlen(digits)-1)) && (len%tmp[i] == j ) )
                        ans[len][i] = num_char[digits[i]-'2'][j];
                    if (i < (strlen(digits)-1) && i >0 ) {
                        for(int k = 0; k < tmp[i-1]; k++) {
                            if ( (len-tmp[i]*k)/tmp[i+1] == j )
                                ans[len][i] = num_char[digits[i]-'2'][j];
                        }
                    }
                }
            }
        }
    }    

    free(tmp);
    *returnSize = size;
    return ans;
}
```