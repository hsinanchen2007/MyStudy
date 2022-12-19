### 解题思路
这一题和打家劫舍第一题类似，多了收尾也不能同时打劫这一个条件。但是最优子结构的取法还是一样的，重点就是做到如何取最值的过程中不同时取收尾。
思路就是创建两个dp数组，一个是[0, length-2],一个是[1, length-1];然后分别求这个范围内的最值。求出来的是不包含首尾的。
dp的取法如下：
dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
取值是上一个的最值或者说上上个的最值加上当前的值。哪一个大就取哪一个。

### 代码

```java
class Solution {
    public int rob(int[] nums) {
        if(nums.length == 0)
            return 0;
        else if(nums.length == 1)
            return nums[0];
        else if(nums.length == 2)
            return Math.max(nums[0], nums[1]);
        
        int[] dp0 = new int[nums.length-1];
        int[] dp1 = new int[nums.length-1];
        
        dp0[0] = nums[0];
        dp0[1] = Math.max(nums[0], nums[1]);

        dp1[0] = nums[1];
        dp1[1] = Math.max(nums[1], nums[2]);


        for(int i = 2; i < nums.length - 1; i++){
            dp0[i] = Math.max(dp0[i-1], dp0[i-2] + nums[i]);
        }
        for(int i = 3, j = 2; i < nums.length; i++,j++){
            dp1[j] = Math.max(dp1[j-1], dp1[j-2] + nums[i]);
        }
        return Math.max(dp0[dp0.length-1], dp1[dp1.length-1]);
    }
}
```