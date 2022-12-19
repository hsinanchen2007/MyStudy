### 解题思路
典型的卡塔兰数问题，使用递归解决。

问题可以转换为：使用一个括号，剩余的括号构造在这个括号内部，和右侧，遍历所有分配的可能。

其中分布在内部和右侧的括号变成子问题。

对于C语言开发者，由于没有内置动态数据结构，因此使用单链表组织结果。


![image.png](https://pic.leetcode-cn.com/e866e9407665270ecfadfe18d2d6c0321eabf49ef2e8f1db16a61cff5f4ff5df-image.png)

### 代码

```c
typedef struct _ret_st
{
    char *ret;
    struct _ret_st *nxt;
}ret_st;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//【算法思路】DFS + 单链表。卡塔兰数。需要动态申请内存。
char ** generateParenthesis(int n, int* returnSize){
    if(n == 0) {
        char **ret = (char **)calloc(1, sizeof(char*));
        ret[0] = "";
        *returnSize = 1;
        return ret;
    }

    if(n == 1) {
        char **ret = (char **)calloc(1, sizeof(char*));
        ret[0] = "()";
        *returnSize = 1;
        return ret;
    }

    ret_st *head = NULL;
    int rcnt = 0;

    //遍历内部和外部放置的结果组合
    for(int i = 0; i < n; i++) {
        int in_size;
        char **sin = generateParenthesis(i, &in_size);
        int out_size;
        char **sout = generateParenthesis(n - i - 1, &out_size);
        //printf("n = %d,i = %d:   ", n, i);
        for(int j = 0; j < in_size; j++) {
            for(int k = 0; k < out_size; k++) {
                //printf("int: %s, out: %s;    ", sin[j], sout[k]);
                char *new = (char *)calloc(n * 2 + 1, sizeof(char));
                int nsize = 0;

                new[nsize++] = '(';

                strncpy(&new[nsize], sin[j], strlen(sin[j]));
                nsize += strlen(sin[j]);

                new[nsize++] = ')';

                strncpy(&new[nsize], sout[k], strlen(sout[k]));
                nsize += strlen(sout[k]);

                new[nsize] = '\0';

                //放入结果链表
                ret_st * cur = (ret_st *)calloc(1, sizeof(ret_st));

                cur->ret = new;

                cur->nxt = head;
                head = cur;
                rcnt++;
            }
        }
    }
    printf("\n");

    //将链表生成结果
    char **ret = (char **)calloc(rcnt, sizeof(char *));

    int rsize = 0;
    ret_st *cur = head;

    while( cur != NULL) {
        ret[rsize++] = cur->ret;
        cur = cur->nxt;
    }

    *returnSize = rsize;
    return ret;
}
```