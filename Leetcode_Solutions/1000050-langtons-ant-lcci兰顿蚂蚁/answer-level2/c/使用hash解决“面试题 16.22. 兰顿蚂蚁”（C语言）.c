### 解题思路
典型的hash表问题，用于描述和快速查找未知边界区间。

1.记录起始位置，方向，各个方向边界

2.逐步前进，先获取当前位置的颜色，并反色（hash表）

3.根据当前位置颜色，方向，找到下一步方向

4.根据下一步方向，前进

5.重复步骤2

6.根据各个方向边界，进行结果输出，注意原点在左上角


![image.png](https://pic.leetcode-cn.com/7c428a3e74110ab587ef571b3eee94a2a49d113844266f1b52d75742386c7959-image.png)


### 代码

```c
#define MMAX(a, b)        ((a) > (b)? (a) : (b))
#define MMIN(a, b)        ((a) < (b)? (a) : (b))

#define RET_LEN     10000

char ret_[RET_LEN][RET_LEN];
char *ret[RET_LEN];

typedef struct _hash_st {
    int key[2];
    int val;
    UT_hash_handle hh;
}hash_st;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//【算法思路】hash。
char** printKMoves(int K, int* returnSize){
    hash_st *pool = (hash_st *)calloc(K, sizeof(hash_st));
    int psize = 0;

    hash_st *head = NULL;

    int cur[2] = {0};
    char dirc = 'R';

    int llen = 0;
    int dlen = 0;
    int rlen = 0;
    int ulen = 0;

    for(int i = 0; i < K; i++) {
        //printf("[%d, %d](%c)    ", cur[0], cur[1], dirc);
        //获得当前黑白状态
        int color;

        hash_st *tmph;
        HASH_FIND(hh, head, cur, sizeof(cur), tmph);
        if(tmph == NULL) {
            hash_st *new = &pool[psize++];
            new->key[0] = cur[0];
            new->key[1] = cur[1];
            new->val = 1;   //没有使用的位置总是空白‘0’，但后面使用过后就为‘1’

            HASH_ADD_KEYPTR(hh, head, new->key, sizeof(new->key), new);

            color = 0;
        } else {
            color = tmph->val;

            tmph->val = (color == 0)? 1 : 0;    //记录使用过后的颜色      
        }

        //转向
        switch (dirc) {
            case 'L':
                dirc = (color == 0)? 'U' : 'D';
                break;
            case 'R':
                dirc = (color == 0)? 'D' : 'U';
                break;
            case 'U':
                dirc = (color == 0)? 'R' : 'L';
                break;
            case 'D':
                dirc = (color == 0)? 'L' : 'R';
                break;
            default:
                printf("dirc ERROR!\n");
        }

        //前进
        switch (dirc) {
            case 'L':
                cur[1]--;
                llen = MMIN(llen, cur[1]);
                break;
            case 'R':
                cur[1]++;
                rlen = MMAX(rlen, cur[1]);
                break;
            case 'U':
                cur[0]++;
                ulen = MMAX(ulen, cur[0]);
                break;
            case 'D':
                cur[0]--;
                dlen = MMIN(dlen, cur[0]);
                break;
            default:
                printf("dirc ERROR!\n");
        }
    }

    //最终位置会填写方向，无需hash操作
    //printf("[%d, %d](%c)\n", cur[0], cur[1], dirc);

    //准备输出结果
    int row = ulen - dlen + 1;
    int col = rlen - llen + 1;

    for(int i = 0; i < row; i++) {
        ret[i] = ret_[i];
        for(int j = 0; j < col; j++) {
            ret[i][j] = '_';
        }
        //收尾
        ret[i][col] = '\0';
    }

    //遍历hash表，刷入所有‘X'，注意坐标原点在左上
    hash_st *tmpc, *tmph;
    HASH_ITER(hh, head, tmpc, tmph) {
        int y = tmpc->key[0];
        int x = tmpc->key[1];
        y = ulen - y;
        x -= llen;

        ret[y][x] = tmpc->val == 1? 'X' : '_';
    }

    ret[ulen - cur[0]][cur[1] - llen] = dirc;

    *returnSize = row;
    return ret;
}
```