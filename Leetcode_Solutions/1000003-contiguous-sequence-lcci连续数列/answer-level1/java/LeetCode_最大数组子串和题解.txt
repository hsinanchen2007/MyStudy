### 解题思路

动态规划思路：

设置一个初始值：maxSum = Integer.MIN_VALUE 子串和初始值 sum = 0

特征方法：

- sum += nums[i] sum代表了一个子串的和
- 如果sum > maxSum => maxSum = sum
- 如果sum < 初始值0 则从新开始计算子串和

### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        int maxSum = Integer.MIN_VALUE;
        int sum = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            maxSum = Math.max(maxSum, sum);
            if (sum < 0) {
                sum = 0;
            }
        }
        return maxSum;
    }
}
```