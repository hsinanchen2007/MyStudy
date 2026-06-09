### 解题如果按照打家劫舍一的思路，可能会出现首尾相连的情况，因此我们引用了并查集的思想，新建find数组，find[i]表示
dp[i]对应的偷窃的第一个房子，如果find[len-1]==0就表示这次偷窃不成功，所以应该把第一个房子去掉或者最后一个房子去掉再执行一次打家劫舍一的代码。
![image.png](https://pic.leetcode-cn.com/04d395bbb1ff5be6599e56d1c1b540eb914377fe5da061ce646918af6636930b-image.png)

### 代码

```java
class Solution {
    public int rob(int[] nums) {
        int len = nums.length;
        int []dp = new  int[len];
        int []find = new  int[len];
        if(len==0) return 0;
        if(len ==1) return nums[0];
        if(len == 2) return Math.max(nums[0],nums[1]);
        dp[0] = nums[0];
        find[0]=0;
        dp[1] = Math.max(nums[0],nums[1]);
        find[1] = nums[0]>nums[1]?0:1;
        for(int i =2;i<len;i++){
            dp[i] = Math.max(dp[i-2]+nums[i],dp[i-1]);
            find[i] = dp[i-2]+nums[i]>dp[i-1]?find[i-2]:find[i-1];
        }
        if(find[len-1]==0) {

            for(int i =2;i<len-1;i++){
                dp[i] = Math.max(dp[i-2]+nums[i],dp[i-1]);
            }
            int max = dp[len-2];
            dp[1]=nums[1];
            dp[2] = Math.max(nums[1],nums[2]);
            for(int i =3;i<len;i++){
                dp[i] = Math.max(dp[i-2]+nums[i],dp[i-1]);
            }
            return dp[len-1]>max?dp[len-1]:max;
        }
        return dp[len-1];
    }
}
```