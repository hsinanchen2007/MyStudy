### 解题思路
1、对于任何一个坐标,计它的索引为index，最后一个索引为lastIndex,它是否可以跳到最后一个位置，有以下几种情况:
   index==lastIndex || nums[index]>lastIndex-index 可以跳
   nums[index]=0 肯定不能跳
   从index+1到nums[index]+index,只要有一个坐标可以跳，那么就可以跳

   所以我们得到一个动态方程f(index) 表示index是否可以跳跃
   f(index) = (index==lastIndex || nums[index]>lastIndex-index) || (i从index+1到nums[index]+index 任意一个f(i)>0即可)
  
2、我们定义一个动态方程数组dp[] 每一个坐标表示其是否可跳跃
   -1表示不可以,0表示未知，1表示可以
   将上述函数定义为
   int calculate(int currentIndex,int[] nums,int[] dp,int lastIndex){
   }
   
   那么我们判断逻辑就是
   int[] dp = new int[nums.length];//数组初始化就是0
   int lastIndex = nums.length-1; 
   dp[lastIndex] = 1//将数组的最后一项初始化为1，表示肯定可以到达
   boolean canJump = calculate(0,nums,dp,lastIndex);

 3、现在我们实现这个动态方程
    int calculate(int currentIndex,int[] nums,int[] dp,int lastIndex){
            if(dp[currentIndex]!=0){
                return dp[currentIndex];
            }
            int numsIndex = nums[currentIndex];     
            if(numsIndex>=lastIndex-currentIndex){
                dp[currentIndex] =1 ;
                return 1;   
            }
            if(numsIndex==0) {
                dp[currentIndex] = -1;
                return -1;
            }
            for(int i = currentIndex+1;i<=numsIndex+currentIndex;i++){
                int canJump = calculate(i,nums,dp,lastIndex);
                if(canJump==1){
                    dp[i] = 1;
                    return 1;
                }
            }
            dp[currentIndex] = -1;
            return -1;
    }
 
注意两点:
1、动态方程组，能初始化几项就尽量多初始化几项，这样可以避免多计算，例如本题中最后一个元素肯定可以到达
2、在递归计算坐标i的过程中，得到准确的dp值的时候，**要将dp[i]赋值**，避免后续重复计算

### 代码

```java
class Solution {

     private int calculate(int currentIndex, int[] nums, int dp[], int lastIndex) {
        if(dp[currentIndex]!=0){
            return dp[currentIndex];
        }
        int numsInIndex = nums[currentIndex];
        if (currentIndex == lastIndex || numsInIndex >= lastIndex - currentIndex) {
            dp[currentIndex] = 1;
            return 1;
        } else {
            if (numsInIndex == 0) {
                dp[currentIndex] = -1;
                return -1;
            }
            for(int i=currentIndex+1;i<=numsInIndex + currentIndex;i++){
                if (calculate(i,nums,dp,lastIndex)==1) {
                    dp[i] = 1;
                    return 1;
                }
            }
        }
        dp[currentIndex] = -1;
        return -1;
    }

    public boolean canJump(int[] nums) {
        if(nums.length==1 || nums==null){
            return true;
        }
        if(nums.length == 2){
            return nums[0]>=1;
        }
        //-1表示不可以 0表示未知 1表示可以
        int[] dp = new int[nums.length];
        int lastIndex = nums.length-1;
        dp[lastIndex] = 1;
        int result = calculate(0, nums, dp,lastIndex);
        return result == 1;
    }
}
```