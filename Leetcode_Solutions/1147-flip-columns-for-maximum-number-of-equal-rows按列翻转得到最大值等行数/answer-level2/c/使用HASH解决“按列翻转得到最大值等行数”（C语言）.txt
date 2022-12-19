### 解题思路
此题需要脑筋急转弯式的问题转换，即两行互补或相等，则可以通过翻转列得到相同行。

使用hash表实现这一过程的快速查找。

![image.png](https://pic.leetcode-cn.com/71b15a1d1ed526127c52ab8c8ef312a9248077db1ca3810fb654451736bd5a33-image.png)

### 代码

```c
/*
 * @lc app=leetcode.cn id=1072 lang=c
 *
 * [1072] 按列翻转得到最大值等行数
 */

// @lc code=start
#define POOL_SIZE   500
#define MMAX(a, b)  ((a) > (b)? (a) : (b))

typedef struct _info_st
{
    int *key;
    int val;
    UT_hash_handle hh;
}info_st;

void reverse(int *r, int len)
{
    for(int i = 0; i < len; i++)
    {
        r[i] = r[i] == 0? 1 : 0;
    }
}

// 【算法思路】hash。脑筋急转弯，两行相同或互补，则可以通过列翻转变为相同
int maxEqualRowsAfterFlips(int** matrix, int matrixSize, int* matrixColSize){
    info_st *pool = (info_st *)calloc(POOL_SIZE, sizeof(info_st));
    int psize = 0;

    info_st *head = NULL;

    int max = 1;

    int row = matrixSize;
    int col = matrixColSize[0];

    for(int i = 0; i < row; i++)
    {
        info_st *cur = &pool[psize];
        cur->key = matrix[i];
        cur->val = 1;

        info_st *tmph;
        HASH_FIND(hh, head, cur->key, col * sizeof(int), tmph);
        
        if(tmph == NULL)
        {
            reverse(cur->key, col);

            HASH_FIND(hh, head, cur->key, col * sizeof(int), tmph);

            if(tmph == NULL)
            {
                HASH_ADD_KEYPTR(hh, head, cur->key, col * sizeof(int), cur);
                psize++;
                continue;
            }

            tmph->val++;
            max = MMAX(max, tmph->val);
            continue;
        }

        tmph->val++;
        max = MMAX(max, tmph->val);
    }
/*
    info_st *cur, *tmph;
    HASH_ITER(hh, head, cur, tmph)
    {
        for(int i = 0; i < col; i++)
        {
            printf("%d  ", cur->key[i]);
        }
        printf("\n");
    }
*/
    return max;
}


// @lc code=end


```