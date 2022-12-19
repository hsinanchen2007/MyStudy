### 解题思路
子问题：从左往右到第i个房屋能偷的最大金额

第i个房屋偷窃情况（状态方程）：
状态（1）偷（2）不偷 ，
总量moneyOne表示状态1情况下偷取总数，moneyTwo表示状态2下偷取总数

状态转移方程：从第i-1个房屋到第i个房屋
（1）第i-1个房屋已经偷取：第i个房屋一定不可偷取，moneyTwo[i] = moneyOne[i-1]
（2）第i-1个房屋未偷取：第i个房屋可偷 moneyOne[i] = moneyTwo[i-1]+nums[i]
可不偷 moneyTwo[i] = moneyTwo[i-1],取两种不偷的最大值存起来
![image.png](https://pic.leetcode-cn.com/94309f700d59d3795f766d59a791586dc7e54a47e8f4f4b6ed1e1962e4ec721d-image.png)

### 代码

```java
class Solution {
    public int rob(int[] nums) {
        
        if (nums == null || nums.length == 0) {
            return 0;
        }
        int moneyOne = nums[0];
        int moneyTwo = 0;
        for (int i=1;i<nums.length;i++) {
            int temp = moneyTwo;
            moneyTwo = Math.max(temp, moneyOne);
            moneyOne = temp + nums[i];
        }
        return Math.max(moneyOne, moneyTwo);
    }
}
```