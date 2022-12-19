### 解题思路
/*
 * 1. 确定状态：
 * 考虑以a[j]结尾的子序列最优解最后一步：
 * 子序列中只有a[j]
 * 当a[j] > 0,则要求a[j-1]为最大值
 * 当a[j] < 0,则要求a[j-1]为最小值
 * 两个子问题：
 * 要求以a[j-1]结尾的最大值以及最小值
 * 2. 转移方程：
 * 最大值：f[j] = max(a[j], max(a[j] * f[j-1], a[j] * g[j-1]))
 * 最小值：g[j] = min(a[j], min(a[j] * f[j-1], a[j] * g[j-1]))
 * 3. 初始值以及边界条件：
 * j > 0
 * 4. 计算顺序
 * f[0] g[0] f[1] g[1] ... f[j] g[j]
 */

### 代码

```c
#define MAX(a, b) ((a) > (b)) ? (a) : (b)
#define MIN(a, b) ((a) < (b)) ? (a) : (b)

/*
 * 1. 确定状态：
 * 考虑以a[j]结尾的子序列最优解最后一步：
 * 子序列中只有a[j]
 * 当a[j] > 0,则要求a[j-1]为最大值
 * 当a[j] < 0,则要求a[j-1]为最小值
 * 两个子问题：
 * 要求以a[j-1]结尾的最大值以及最小值
 * 2. 转移方程：
 * 最大值：f[j] = max(a[j], max(a[j] * f[j-1], a[j] * g[j-1]))
 * 最小值：g[j] = min(a[j], min(a[j] * f[j-1], a[j] * g[j-1]))
 * 3. 初始值以及边界条件：
 * j > 0
 * 4. 计算顺序
 * f[0] g[0] f[1] g[1] ... f[j] g[j]
 */
int maxProduct(int* a, int numsSize){
    int *f = (int *)malloc(numsSize * sizeof(int));
    int *g = (int *)malloc(numsSize * sizeof(int));
    int res;

    if (numsSize == 0) {
        return 0;
    }

    for (int i = 0; i < numsSize; i++) {
        f[i] = a[i];
        /* 求最大子序列 */
        if (i > 0) {
            f[i] = MAX(a[i], MAX(a[i] * f[i-1], a[i] * g[i - 1]));
        }
        g[i] = a[i];
        /* 求最小子序列 */
        if (i > 0) {
            g[i] = MIN(a[i], MIN(a[i] * f[i-1], a[i] * g[i - 1]));
        }
        res = MAX(res, f[i]);
    }

    return res;
}
```