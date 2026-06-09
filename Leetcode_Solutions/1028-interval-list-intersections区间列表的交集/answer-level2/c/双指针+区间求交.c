### 解题思路
    常规区间列表求交集是：仅给定一个区间列表，求其中的区间交集，做法是按区间起点递增排序，然后两两求交。

    本题是给定两个已排序列表求其交集：因为区间已经排序，可以定义两个指针i，j，分别指向数组A，B的首个区间，
    然后不断往后移动i，j指针，求得区间交集，直到某个指针到达数组边界，即可停止。具体合并时，可以将其分为
    两类情况：
    a、两区间无交集，对应代码注释：条件1或条件2满足。
    b、两区间有交集，对应代码注释3。
    注意：条件3中，当有y1 == y2时，两个指针i,j同时要加1。！！！

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int** intervalIntersection(int** A, int ASize, int* AColSize, int** B, int BSize, int* BColSize, int* returnSize, int** returnColumnSizes){
    int **res = (int **) malloc(sizeof(int *) * 2000);
    *returnColumnSizes = (int *) malloc(sizeof(int) * 2000);
    int idx = 0;
    for (int i = 0, j = 0; i < ASize && j < BSize;) {
        //区间不相交
        int x1 = A[i][0], y1 = A[i][1], x2 = B[j][0], y2 = B[j][1];
        if (y1 < x2) {  \\条件1
            i++;
        } else if (y2 < x1) { \\条件2
            j++;
        } else {  \\条件3
            //必有交集
            int max_x = max(x1, x2);
            int min_y = min(y1, y2);
            res[idx] = (int *) malloc(sizeof(int) * 2);
            res[idx][0] = max_x;
            res[idx++][1] = min_y;
            if (y1 == y2) {
                i++;
                j++;
            } else if (y1 < y2) {
                i++;
            } else {
                j++;
            }
        }
    }
    for (int i = 0; i < idx; i++) {
        (*returnColumnSizes)[i] = 2;
    }
    *returnSize = idx;
    return res;
}
```