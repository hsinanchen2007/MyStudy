### 解题思路
此处撰写解题思路

参考了labuladong的讲解
https://leetcode-cn.com/problems/friend-circles/solution/union-find-suan-fa-xiang-jie-by-labuladong/

### 代码

```c
int g_arr[10000];
int g_count;
int g_size[10000];
int Find(int x)
{
    while (g_arr[x] != x) {
        g_arr[x] = g_arr[g_arr[x]];
        x = g_arr[x];
    }

    return x;
}

bool IsConnected(int x, int y)
{
    return Find(x) == Find(y);
}

void UnionEle(int x, int y)
{
    int xparent = Find(x);
    int yparent = Find(y);
    if (xparent == yparent) {
        return;
    }

    if (g_size[xparent] > g_size[yparent]) {
        g_arr[yparent] = xparent;
        g_size[xparent] += g_size[yparent];
    } else {
        g_arr[xparent] = yparent;
        g_size[yparent] += g_size[xparent];
    }
    g_count--;
}

int findCircleNum(int** M, int MSize, int* MColSize){
    if (M == NULL || MSize == 0 || MColSize == 0) {
        return 0;
    }

    g_count = MSize;
    int i;
    for(i = 0; i < MSize; i++) {
        g_arr[i] = i;
        g_size[i] = 1;
    }

    int j;
    for (i = 0; i < MSize; i++) {
        for (j = 0; j < i; j++) { // 第i个人跟前面的人比较一下，是否是朋友
            if (M[i][j] == 1) {
                UnionEle(i, j);
            }
        }
    }

    return g_count;

}
```