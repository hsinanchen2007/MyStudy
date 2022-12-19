### 解题思路
由于题目不要求最短距离，并且需要返回成功路径，因此选择DFS解决。

建立路标数组，将走过的位置置1进行标记.

对于C语言而言，返回路径信息是个难点，使用单链表解决。

一旦找到路径，在DFS返回时，在链表中加入当前位置节点即可。

![image.png](https://pic.leetcode-cn.com/9fbae6f7d2254b5dab4879a7d094e72df7e6f4e0f6cdaafe3b7260c64ddeb925-image.png)


### 代码

```c
typedef struct _info_st
{
    int y;
    int x;
    struct _info_st *nxt;
}info_st;

int flags[100][100];

int row, col;
int **oo;

info_st * helper(int y, int x, int *returnSize)
{
    if(y >= row || x >= col || oo[y][x] == 1)
    {
        *returnSize = 0;
        return NULL;
    }

    if(y == row - 1 && x == col - 1)
    {
        info_st *new = (info_st *)calloc(1, sizeof(info_st));
        new->y = y;
        new->x = x;

        *returnSize = 1;
        return new;
    }

    //处理右侧
    if(x < col - 1 && flags[y][x + 1] == 0 && oo[y][x + 1] == 0)
    {
        int rsize;

        flags[y][x + 1] = 1;

        info_st *ret = helper(y, x + 1, &rsize);

        flags[y][x + 1] = 0;

        if(rsize != 0)
        {
            info_st *new = (info_st *)calloc(1, sizeof(info_st));
            new->y = y;
            new->x = x;

            new->nxt = ret;

            *returnSize = rsize + 1;
            return new;
        }
    }

    //处理下方
    if(y < row - 1 && flags[y + 1][x] == 0 && oo[y + 1][x] == 0)
    {
        int rsize;

        flags[y + 1][x] = 1;

        info_st *ret = helper(y + 1, x, &rsize);

        flags[y + 1][x] = 0;

        if(rsize != 0)
        {
            info_st *new = (info_st *)calloc(1, sizeof(info_st));
            new->y = y;
            new->x = x;

            new->nxt = ret;

            *returnSize = rsize + 1;
            return new;
        }
    }

    *returnSize = 0;
    return NULL;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
//【算法思路】DFS+单链表.因为题目没有要求求最短距离，但要返回之前走过的路径，因此直接使用dfs。
//          一旦可以到达目的地，则将结果加在返回的链表中
int** pathWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize, int* returnSize, int** returnColumnSizes){
    row = obstacleGridSize;
    col = obstacleGridColSize[0];
    oo = obstacleGrid;

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            flags[i][j] = 0;
        }
    }

    int rsize;

    flags[0][0] = 1;
    
    info_st *cur = helper(0, 0, &rsize);

    if(rsize == 0)
    {
        *returnSize = 0;
        return NULL;
    }

    int **ret = (int **)calloc(rsize, sizeof(int *));
    int *ret_col = (int *)calloc(rsize, sizeof(int));

    int rid = 0;
    while(cur != NULL)
    {
        ret[rid] = cur;
        ret_col[rid] = 2;
        rid++;
        cur = cur->nxt;
    }

    *returnSize = rsize;
    *returnColumnSizes = ret_col;
    return ret;
}
```