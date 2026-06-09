### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int comp(const void* arga, const void* argb)
{
    long long x = *(*((int**)arga));
    long long y = *(*((int**)arga) + 1);

    long long a = *(*((int**)argb));
    long long b = *(*((int**)argb) + 1);

    return (x*x + y*y) - (a*a + b*b);
}


int** kClosest(int** points, int pointsSize, int* pointsColSize, int K, int* returnSize, int** returnColumnSizes){
    if (points == NULL || pointsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    qsort(points, pointsSize, sizeof(points[0]), comp);

    *returnSize = K > pointsSize ? pointsSize : K;
    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    for (int i = 0 ; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 2;
    }
    return points;
}
```