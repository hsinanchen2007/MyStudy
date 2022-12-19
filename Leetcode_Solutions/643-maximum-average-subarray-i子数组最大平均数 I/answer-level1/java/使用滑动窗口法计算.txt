### 解题思路

先计算第0到k-1数的和，然后开始滑动计算，减去最前面的，加上最后面的，比较当前和的大小，最后返回和最大值的平均数

![image.png](https://pic.leetcode-cn.com/ef29de0f0b523513d687f70e54300382dfb813bd1b84da9f6c7a5d8bfa59cdd2-image.png)


### 代码

```java
class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        int ret = sum;
        int i = k;
        while (i < nums.length) {
            sum = sum + nums[i] - nums[i - k];
            ret = Math.max(ret, sum);
            i++;
        }
        return ret * 1.0 / k;
    }
}
```