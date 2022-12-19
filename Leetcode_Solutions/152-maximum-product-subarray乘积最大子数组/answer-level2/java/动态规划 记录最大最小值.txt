### 解题思路
如果序列中不包含负数的话情况比较简单，只要用数组`dp[i]`记录所有以第i个数为结尾的子序列的最大乘积。当`dp[i-1]>1`时，`dp[i]=dp[i-1]*nums[i]`;当`dp[i-1]<1`时，`dp[i]=nums[i]`。
考虑有正负的情况，可以使用两个数组，`dpP[i]`记录所有以第i个数为结尾的子序列的最大乘积，`dpN[i]`记录所有以第i个数为结尾的子序列的最小成绩，根据`nums[i]`的符号进行讨论。

### 代码

```java
class Solution {
    public int maxProduct(int[] nums) {
        int[] dpP = new int[nums.length];
        int[] dpN = new int[nums.length];
        dpP[0] = nums[0];
        dpN[0] = nums[0];
        int maxPro = nums[0];
        for(int i = 1; i < nums.length; i++) {
            if(nums[i] >= 0) {
                dpP[i] = Math.max(dpP[i - 1], 1) * nums[i];
                dpN[i] = Math.min(dpN[i - 1], 1) * nums[i];
            }
            else {
                dpP[i] = Math.min(dpN[i - 1], 1) * nums[i];
                dpN[i] = Math.max(dpP[i - 1], 1) * nums[i];
            }
            if(dpP[i] > maxPro) {
                maxPro = dpP[i];
            }
        }
        return maxPro;
    }
}
```