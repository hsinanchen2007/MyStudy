### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/858ad08670768615b8d55756b7519398baf315660551751cabd2de3ab67012de-image.png)
我的另一种方法：https://leetcode-cn.com/submissions/detail/54956504/
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **g_res;
int g_res_index;

void swap(char *S, char aindex, char bindex)
{
    char tmp = S[aindex];
    S[aindex] = S[bindex];
    S[bindex] = tmp;
}

void perm(char *S, int offset)
{
    //printf("S = %s, offset = %d\n", S, offset);
    if (offset == strlen(S) - 1) {
        g_res[g_res_index] = calloc(20, sizeof(char));
        strcpy(g_res[g_res_index++], S);
        //printf("S = %s\n", S);
        return;
    }
    else {
        for (int i = offset; i < strlen(S); i++) {
            swap(S, offset, i);
            perm(S, offset + 1);
            swap(S, offset, i);
        }
    }
}

char** permutation(char* S, int* returnSize){
    g_res = calloc(9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 2, sizeof(char*));  //more input
    g_res_index = 0;

    perm(S, 0);

    *returnSize = g_res_index;
    return g_res;
}
```