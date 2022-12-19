### 解题思路
利用了并查集的特点，即**冗余连接的两个节点，其对应的根节点相同**，这里给出C语言的解法。

在标准并查集代码模板中，增加全局遍历is_redu监控在join过程中是否出现x和y的根相同的情况。

![image.png](https://pic.leetcode-cn.com/15adfc69391eafb33366cc03d7809b6111218eb43032ecf89b316f50502a842c-image.png)


### 代码

```c

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MMAX(a, b)      ((a) > (b)? (a) : (b))

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

bool is_redu;

int find(int *fa, int x) {
    if(x == fa[x]) {
        return x;
    }

    fa[x] = find(fa, fa[x]);
    return fa[x];
}

void join(int *fa, int x, int y) {
    int xx = find(fa, x);
    int yy = find(fa, y);

    if(xx == yy) {
        is_redu = true;
        return xx;
    }

    if(xx < yy) {
        fa[yy] = xx;
    } else {
        fa[xx] = yy;
    }
}

int ret[2];

//【算法思路】并查集。利用并查集的特点：当出现冗余连接时，连接的两个节点，其根节点相同。
int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize){
    //找到最大值N
    int max = 0;
    for(int i = 0; i < edgesSize; i++) {
        max = MMAX(max, edges[i][0]);
        max = MMAX(max, edges[i][1]);
    }

    int *fa = (int *)calloc(max + 1, sizeof(int));

    for(int i = 0; i <= max; i++) {
        fa[i] = i;
    }

    is_redu = false;
    for(int i = 0; i < edgesSize; i++) {
        int x = edges[i][0];
        int y = edges[i][1];

        join(fa, x, y);

        if(is_redu == true) {
            ret[0] = x;
            ret[1] = y;
            break;
        }
    }

    *returnSize = 2;
    return ret;
}
```