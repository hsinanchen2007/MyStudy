### 解题思路
![image.png](https://pic.leetcode-cn.com/5a37cf77251ef901127844f74d1d1dd8011f134399724e0663a84574a96783f6-image.png)

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* T, int TSize, int* returnSize){
    if (TSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    int *ans = (int *)malloc(sizeof(int) * TSize);
    memset(ans, 0, sizeof(int) * TSize);

    int left, right;
    ans[TSize - 1] = 0;
    /* 因采用当前值与右值相比，采用从左到右遍历，需要大量重复计算，从右到左，可记录后续结果，类似动态规划 */
    for (left = TSize - 2; left >= 0; left--) {
        /* 若左值大于右值，则可以跳过比右值小的位数，减少重复计算 */
        for (right = left + 1; right < TSize; right += ans[right]) {
            if (T[left] < T[right]) {
                ans[left] = right - left;
                break;
            } 
            /* 当前值大于右侧值，且右侧值反馈其右侧无更大值，填充0，结束此位置计算 */
            if (ans[right] == 0) {
                ans[left] = 0;
                break;
            }
        }
    }

    *returnSize = TSize;
    return ans;
}
```