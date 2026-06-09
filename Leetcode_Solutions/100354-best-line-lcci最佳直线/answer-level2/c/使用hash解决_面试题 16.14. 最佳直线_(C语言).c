### 解题思路
1.遍历坐标点。在每次遍历中，固定左边的点；

2.计算两两之间的斜率，

3.将斜率作为hash进行保存和统计。

4.返回结果

对于C语言开发者，需要注意：

a.注意除数为0的情况，C语言要定义FLT_MAX;

b.以及被除数为0的情况，需要直接等于0（计算会失真）；

![image.png](https://pic.leetcode-cn.com/a1332acfd09547a462bab5a6476758447d55ca46c9d706a27239ab770d406a14-image.png)


### 代码

```c

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define YX_MAX     3.4e+38

typedef struct _hash_st {
    float key;
    int s;
    int e;
    int val;
    UT_hash_handle hh;
}hash_st;

int ret[2];

//【算法思路】hash。判断每个点和后面点的斜率，以斜率作为hash的key.
// 注意float的精度可以满足要求，但是要处理diff_x == 0和diff_y == 0的情况。
int* bestLine(int** points, int pointsSize, int* pointsColSize, int* returnSize){
    hash_st *pool = (hash_st *)calloc(pointsSize * pointsSize, sizeof(hash_st));
    int psize = 0;

    hash_st **heads = (hash_st **)calloc(pointsSize - 1, sizeof(hash_st *));
    hash_st *maxh = NULL;

    for(int i = 0; i < pointsSize - 1; i++) {
        hash_st *head = heads[i];
        for(int j = i + 1; j < pointsSize; j++) {
            float yx;
            //先查找斜率是否找到，找不到则记录一个新hash
            int xx = points[i][0] - points[j][0];
            int yy = points[i][1] - points[j][1];

            if(xx == 0) {
                yx = YX_MAX;
            } else if(yy == 0) {
                yx = 0.0;   //此处注意，直接计算会失真！！
            } else {
                yx = (float)yy / xx;
            }
            hash_st *tmph;
            HASH_FIND(hh, head, &yx, sizeof(float), tmph);
            if(tmph == NULL) {
                hash_st *new = &pool[psize++];
                new->key = yx;
                new->s = i;
                new->e = j;
                new->val = 1;

                if(maxh == NULL) {
                    maxh = new;
                }

                HASH_ADD_KEYPTR(hh, head, &(new->key), sizeof(float), new);
            } else {
                tmph->val++;
                if(tmph->val > maxh->val) {
                    maxh = tmph;
                }
            }
        }
    }

    ret[0] = maxh->s;
    ret[1] = maxh->e;

    printf("max = %d\n", maxh->val);

    *returnSize = 2;
    return ret;
}

```