### 解题思路
本题是DFS+memo的典型代表，需要重点掌握，这里给出C语言的解法。

另外，本题初看和背包类问题很像，但是无法直接套用背包模型，因此使用DFS解决。

本题的难点有3个：

1.memo的数据结构。直观想法memo使用6维数组，但是这样编程非常不友好，因此改为1维数组+计算id实现。

2.操作目标商品。由于结果为6维，因此构造独立函数，用于计算购买某礼包后还需要的商品数，简化代码。

3.剩余商品的补齐。由于直接使用礼包最终会剩余某些商品无法购买，因此**在迭代时增加一级，用于完成所有商品的购买**。

![image.png](https://pic.leetcode-cn.com/d667c55ad77dc2d412ee8a1cc8d932920a5b758f9e9be35c2e8a88eabaa477a3-image.png)


### 代码

```c
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define MMAX(a, b)        ((a) > (b)? (a) : (b))
#define MMIN(a, b)        ((a) < (b)? (a) : (b))

int *memo;

//根据当前需购买物品，换算成memo的id
int get_id(int* needs, int needsSize) {
    int id = 0;

    for(int i = 0; i < needsSize; i++) {
        id = id * 6 + needs[i];
    }

    return id;
}

//根据当前需购买物品，当前礼包和礼包购买数量，计算下一次需购买物品的数量
bool get_needs(int *new_needs, int* needs, int needsSize, int *special, int num) {
    for(int i = 0; i < needsSize; i++) {
        new_needs[i] = needs[i] - special[i] * num;

        if(new_needs[i] < 0) {
            return false;
        }
    }

    return true;
}

int helper(int* price, int priceSize, int** special, int specialSize, int* specialColSize, int* needs, int needsSize, int id) {
    //关键：无法使用大礼包，单独购买剩下的物品
    if(id == specialSize) {
        int cost = 0;
        for(int i = 0; i < needsSize; i++) {
            cost += needs[i] * price[i];
        }
        return cost;
    }

    int mid = get_id(needs, needsSize);
    //printf("mid = %d\n", mid);

    if(memo[mid] != 0) {
/*
        for(int k = 0; k < needsSize; k++) {
            printf("%d  ", needs[k]);
        }
        printf("; min = %d\n", memo[mid] - 1);
*/
        return memo[mid] - 1;
    }

    int min = INT_MAX;
    //对于第id个大礼包，判断使用不同当前礼包的情况，使用的最小开销
    for(int i = 0; i <= 6; i++) {
        int new_needs[6];
        if(get_needs(new_needs, needs, needsSize, special[id], i) == false) {
            //表示已经不足购买一个大礼包
            break;
        }

        //当前购买礼包的开销 + 购买剩下物品的开销
        min = MMIN(min, special[id][needsSize] * i + helper(price, priceSize, special, specialSize, specialColSize, new_needs, needsSize, id + 1));
    }

    memo[mid] = min == INT_MAX? INT_MAX : min + 1;
/*
    for(int k = 0; k < needsSize; k++) {
        printf("%d  ", needs[k]);
    }
    printf("; min = %d\n", min);
*/
    return min;
}

//【算法思路】DFS+memo.
// 在DP没有把握的情况下，优选DFS。
int shoppingOffers(int* price, int priceSize, int** special, int specialSize, int* specialColSize, int* needs, int needsSize){
    int mlen = pow(7, needsSize);
    memo = (int *)calloc(mlen, sizeof(int));

    int ret = helper(price, priceSize, special, specialSize, specialColSize, needs, needsSize, 0);

    return ret;
}
```