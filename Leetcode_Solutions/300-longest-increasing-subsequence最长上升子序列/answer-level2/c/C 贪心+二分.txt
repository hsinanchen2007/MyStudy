### 解题思路
贪心加二分的C语言解法，思路基本一样。

### 代码

```c
int lengthOfLIS(int* nums, int numsSize){
    /* 长度为i的递增序列的最小的最后一个数字 */
    int *dp = malloc(sizeof(int) * numsSize);
    memset(dp, 0, sizeof(int) * numsSize);
    int start = 0;
    for (int i = 0; i < numsSize; i++) {
        int cur = nums[i];
        /* 二分查找左侧边界 */
        int left = 0;
        int right = start;
        while (left < right) {
            int mid = (left + right) / 2;
            if (dp[mid] > cur) {
                right = mid;
            } else if (dp[mid] < cur) {
                left = mid + 1; /* 左侧边界 */
            } else {
                right = mid;
            }
        }

        /* 没找到更新dp,说明集合内没有元素比该元素大，扩展dp值 */
        if (left == start) {
            start ++;
        }
        /* 找没找到都更新dp最小元素 */
        dp[left] = cur;
    }
    free(dp);
    /* 返回最后dp的最大长度 */
    return start;
}
```