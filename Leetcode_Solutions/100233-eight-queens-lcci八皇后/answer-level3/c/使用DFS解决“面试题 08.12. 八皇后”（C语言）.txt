### 解题思路
经典的深度优先遍历题目，这里给出C语言的解法。

1.申请标志矩阵

2.建立递归函数，如果是最后一行，开辟结果空间

3.每次处理一行，处理之前先判断是否有空位，没有则返回

4.如果有空位，则打标志，注意只需要打当前行之后几行

5.调用递归函数处理下一行，直至结束

注意：
（1）标志只需要打在后几行
（2）在最后一行，申请空间

![image.png](https://pic.leetcode-cn.com/847531f9621aa4258d6a7b43f885c2fe8ceb094ec6df942bb056428800d9b15a-image.png)


### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define NMAX_LEN    1000

typedef struct _ret_st {
    char **ret;
    struct _ret_st *nxt;
}ret_st;

int nn;

int flags[NMAX_LEN][NMAX_LEN];

char ***helper(int id, int *returnSize) {
    //printf("id = %d\n", id);
    //最后必然只剩余一个位置
    if(id == nn - 1) {
        //先判断是否有结果
        int fid;
        bool find = false;
        for(int i = 0; i < nn; i++) {
            if(flags[id][i] == 0) {
                find = true;
                fid = i;
                break;
            }
        }
        if(find == false) {
            *returnSize = 0;
            return NULL;
        }

        char ***ret = (char ***)calloc(1, sizeof(char **));
        char **ret_ = (char**)calloc(nn, sizeof(char *));

        ret[0] = ret_;
        for(int i = 0; i < nn; i++) {
            ret[0][i] = (char *)calloc(nn + 1, sizeof(char));

            for(int j = 0; j < nn; j++) {
                ret[0][i][j] = '.';
            }
        }

        ret[0][nn - 1][fid] = 'Q';

        *returnSize = 1;
        return ret;
    }

    ret_st *head = NULL;
    int rsize = 0;

    for(int i = 0; i < nn; i++) {
        if(flags[id][i] != 0) {
            continue;
        }

        //先进行标记，只标记后面几行
        //b
        for(int cnt = id + 1; cnt < nn; cnt++) {
            flags[cnt][i]++;
        }
        //bl
        int n = i;
        for(int cnt = id + 1; cnt < nn; cnt++) {
            if(n - 1 >= 0) {
                flags[cnt][n - 1]++;
                n--;
            } else {
                break;
            }
        }
        //br
        n = i;
        for(int cnt = id + 1; cnt < nn; cnt++) {
            if(n + 1 < nn) {
                flags[cnt][n + 1]++;
                n++;
            } else {
                break;
            }
        }

        int tmp_rsize;
        char ***ret = helper(id + 1, &tmp_rsize);
        //printf("id = %d, tmp_rsize = %d\n", id, tmp_rsize);
/*
        printf("id = %d\n", id);
        for(int cnt = 0; cnt < tmp_rsize; cnt++) {
            for(int i_ = 0; i_ < nn; i_++) {
                for(int j_ = 0; j_ < nn; j_++) {
                    printf("%c  ", ret[cnt][i_][j_]);
                }
                printf("\n");
            }
            printf("----------\n");
        }
*/
        //如果有结果返回，则串接结果
        if(tmp_rsize != 0) {
            for(int m = 0; m < tmp_rsize; m++) {
                ret[m][id][i] = 'Q';

                ret_st *new = (ret_st *)calloc(1, sizeof(ret_st));
                new->ret = ret[m];

                new->nxt = head;
                head = new;

                rsize++;
            }
        }

        //将本次标记还原
        //b
        for(int cnt = id + 1; cnt < nn; cnt++) {
            flags[cnt][i]--;
        }
        //bl
        n = i;
        for(int cnt = id + 1; cnt < nn; cnt++) {
            if(n - 1 >= 0) {
                flags[cnt][n - 1]--;
                n--;
            } else {
                break;
            }
        }
        //br
        n = i;
        for(int cnt = id + 1; cnt < nn; cnt++) {
            if(n + 1 < nn) {
                flags[cnt][n + 1]--;
                n++;
            } else {
                break;
            }
        }
    }
    
    if(rsize == 0) {
        *returnSize = 0;
        return NULL;
    }

    //将结果串接
    char ***ret = (char ***)calloc(rsize, sizeof(char **));
    int rid = 0;

    ret_st *cur = head;
    while (cur != NULL) {
        ret[rid++] = cur->ret;
        cur = cur->nxt;
    }

    *returnSize = rsize;
    return ret;
}

//【算法思路】DFS + 单链表。每走一步，则标记本步影响。走下一步前，先清除本步影响。
char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes){
    if(n == 0) {
        return NULL;
    }

    nn = n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            flags[i][j] = 0;
        }
    }

    char *** ret = helper(0, returnSize);

    int *ret_col = (int *)calloc(*returnSize, sizeof(int));
    for(int i = 0; i < *returnSize; i++) {
        ret_col[i] = n;
    }

    *returnColumnSizes = ret_col;
    return ret;
}
```