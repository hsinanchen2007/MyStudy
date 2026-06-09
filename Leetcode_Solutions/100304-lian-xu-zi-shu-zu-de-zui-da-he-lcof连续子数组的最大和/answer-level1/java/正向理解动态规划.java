### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
        public int maxSubArray(int[] nums) {
            // 对于以nums[i]为开头的数字，有 [-2],[-2,1],[-2,1,-3]等……
            // 所有以nums[i]为开头的数字囊括了所有数字，所以我们可以拆开来看，先开以nums[0]为开头的数组
            // 可以发现 nums[0]是在所有以nums[1]为开头的子数组，在其之上前面加了个-2的结果
            // 再来定义 dp[i]代表以nums[i]开头的子数组中有最大和的那一个。
            // 可以知道 dp[0]= max(nums[0],nums[0]+dp[1])
            // 边界：对于dp[n-1]=nums[n-1],dp[n-2]=max(nums[n-2],nums[n-2]+dp[n-1])
            if(nums.length==0) return 0;
            if(nums.length==1) return nums[0];
            int[] dp = new int[nums.length];
            dp[nums.length-1] = nums[nums.length-1];
            int max = dp[nums.length-1];
            for( int i=nums.length-2; i>=0;i-- ){
                dp[i] = Math.max(dp[i+1]+nums[i],nums[i]);
                max = Math.max(dp[i],max);
            }
            return max;
        }
    }
```