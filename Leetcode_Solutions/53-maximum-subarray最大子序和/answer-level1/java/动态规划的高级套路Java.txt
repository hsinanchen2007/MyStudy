### 解题思路
https://zhuanlan.zhihu.com/p/107457744
![图片.png](https://pic.leetcode-cn.com/c5ad3b4082021c1bd9f528c78bb01d668dd22b43bc77000092a3a0f93642da6f-%E5%9B%BE%E7%89%87.png)

### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        int[] dp=new int[nums.length];
        int max=nums[0];
        dp[0]=nums[0];
        for(int i=1;i<nums.length;i++){
            dp[i]=Math.max(nums[i],nums[i]+dp[i-1]);
            max=Math.max(dp[i],max);
        }
        return max;
    }
}
```