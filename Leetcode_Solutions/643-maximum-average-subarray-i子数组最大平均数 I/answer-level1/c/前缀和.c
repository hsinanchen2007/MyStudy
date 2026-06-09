### 解题思路
此处撰写解题思路

### 代码

```c
#define MAX(x, y) (x > y ? x : y)
double findMaxAverage(int* nums, int numsSize, int k){
    double ans = 0;
    int pre_sum[numsSize + 1];
    pre_sum[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        pre_sum[i] = pre_sum[i - 1] + nums[i];
    }
    ans = (double)pre_sum[k - 1] / k;
    for (int i = 0; i < numsSize - k; i++) {
        ans = MAX(ans, (double)(pre_sum[i+k] - pre_sum[i]) / k);
    }
    return ans;
}
```