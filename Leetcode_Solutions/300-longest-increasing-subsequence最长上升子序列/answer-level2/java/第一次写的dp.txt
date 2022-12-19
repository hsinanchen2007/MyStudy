### 解题思路
我知道我是逃不过dp的，看到这题还算简单就学习一下
一般来说找最值之类的就可以考虑dp，我脚着最重要的是dp的状态转移方程，还有“状态”的定义。我理解这个题的状态就是到目前（j）为止最长的子序列,如果想遍历所有的数字，j就得继续往后走，然后每一次都得检查一下前面的最长，所以复杂度害挺高
当检查下一个i的时候，计算是不是递增的？如果是的话长度可以++，但是也要检查一下长度就算++了，也不一定是当前最长，所以把当前最长保存在这里，也算是维持“状态”的定义吧
### 代码

```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        int length=nums.length;
        if(length==0){
            return 0;
        }
        int[] dp=new int[length];
        Arrays.fill(dp,1);
        for(int i=0;i<length;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i]=Math.max(dp[i],dp[j]+1);
                }
            }
        }
        Arrays.sort(dp);
        return dp[length-1];
    }
}
```