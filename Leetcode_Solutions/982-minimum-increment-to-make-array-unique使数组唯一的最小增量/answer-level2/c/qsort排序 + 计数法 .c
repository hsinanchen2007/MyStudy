
总体思路：
1. 先用qsort从小到大排序；
2. 扫描数组计数。

从小到大排过序后，整个数组应该是不降的序列。
A是数组序列，cnt是累计需要增加的次数。
当检测到A[i]==A[i-1]时，为了避免重复，A[i] = A[i - 1] + 1, 此时cnt = cnt + 1;
当检测到A[i]<A[i-1]时，意味着之前的序列一定出现过==的情况，数字已经增加过了，才会出现下降的情况。
这个时候A[i]的目标值应该是target = A[i - 1] + 1, 此时需要cnt += target - A[i]; 同时，A[i] = target;
当检测到A[i]>A[i-1]时,说明目前截止到序列A[0:i]都没有重复的数字。
综上，合并<和==的情况，代码如下。

```
int compFun(void *a, void *b)
{
    return (*(int*)a - *(int*)b);
}

int minIncrementForUnique(int* A, int ASize)
{
    qsort(A, ASize, sizeof(int), compFun);
    int cnt = 0;
    for (int i = 1; i < ASize; i++) {
        if (A[i] <= A[i - 1]) {
            cnt += A[i - 1] + 1 - A[i];
            A[i] = A[i - 1] + 1;
        }
    }
    return cnt;
}
```
结果：
![image.png](https://pic.leetcode-cn.com/214fdf5c28fb9ea644b0f99c156ffe6c5542971e7b38f6608475bd6032447760-image.png)

