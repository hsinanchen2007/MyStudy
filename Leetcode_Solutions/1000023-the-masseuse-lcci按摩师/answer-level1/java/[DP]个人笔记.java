### 解题思路
记录下自己的做题思路：
推理反向走
目标求dp[last]
反推dp[last的前一项]
last的前一个有两种情况：
1. 不选第last天，即直接推回last-1状态，结果为dp[last-1]
2. 选第last天，加上该天的数量nums[last]，然后推上一个可选之日f(i)=i-2，因为说了要隔一天，那就要多回去一天i-1-1,结果为dp[last-2]+nums[last]

然后选择两种情况中更大的
即dp[last] = MAX( dp[last-1], dp[last-2]+nums[last] )
公式就出来了
dp[i] = Math.max( dp[i-1], dp[i-2]+nums[i] );
i需要遍历0~(nums.length-1)
避免i-1和i-2越界，先算好初值
dp[0] = nums[0];
dp[1] = nums[1];
等等，0和1哪个更大？
dp[1] = Math.max( dp[0], dp[1] );
前面是初始思路，可以简化成dp[1] = Math.max( dp[0], nums[1] );


### 代码

```java
class Solution {
    public int massage(int[] nums) {
        if( nums == null || nums.length == 0 ) return 0;
        if( nums.length == 1 ) return nums[0];
        int len = nums.length;
        int[] dp = new int[len];
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[1] = dp[1] > dp[0] ? dp[1] : dp[0];
        for( int i = 2 ; i < len ; i++ ){
            dp[i] = Math.max( dp[i-1] , dp[i-2]+nums[i] );
        }
        return dp[len-1];
    }
}
```