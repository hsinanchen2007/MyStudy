### 解题思路
每次递归进来的字符串都不一样，所以要搞一个栈上局部变量，拷贝过来再修改。


给定一个字符串S，通过将字符串S中的每个字母转变大小写，我们可以获得一个新的字符串。返回所有可能得到的字符串集合。

示例:
输入: S = "a1b2"
输出: ["a1b2", "a1B2", "A1b2", "A1B2"]

输入: S = "3z4"
输出: ["3z4", "3Z4"]

输入: S = "12345"
输出: ["12345"]


### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int **g_res;
int len;
int k;

void dfs(char * S, int cur, char *res){

    if (cur == len){
        g_res[k] = malloc((len + 1)*sizeof(int));
        //memset(g_res[k], 0, (len + 1)*sizeof(int));
        //printf("res = %s\n",res);
        strcpy(g_res[k++], res);
        return;
    }

    char temp[16] = {0};
    strcpy(temp, res);
    cur++;
    temp[cur] = S[cur];
    dfs(S, cur, temp);
    if (S[cur] >= 97 && S[cur] <= 122){
        temp[cur] = S[cur] - 32;
        dfs(S, cur, temp);
    } else if (S[cur] >= 65 && S[cur] <= 90){
        temp[cur] = S[cur] + 32;
        dfs(S, cur, temp);
    }

}

char ** letterCasePermutation(char * S, int* returnSize){
    char temp[4] = {0};

    len = strlen(S);
    g_res = malloc(5000 * sizeof(char *));
    k = 0;
    dfs(S, -1, temp);

    *returnSize = k;
    return g_res;
}
```