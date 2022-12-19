### 解题思路
![QQ截图20200319153914.png](https://pic.leetcode-cn.com/f8e6f75d8e19f5fe5b8db12c1e03ad419e5a375218848eb770d8f5bf16920134-QQ%E6%88%AA%E5%9B%BE20200319153914.png)

要求第0家和第n-1家永远也不能同时被偷，所以考虑第0家的时候不要包含第n-1家，考虑第n-1家的时候不要包含第0家
用这两个线性表分别去做198题的动态规划，取大的即可
### 代码

```java
class Solution {
    public int rob(int[] nums) {
        if(nums.length==0){
            return 0;
        }
        if(nums.length==1){
            return nums[0];
        }
        //length>=2
        int dp_i_2=0;
        int dp_i_1=0;
        int dp_max1=nums[0];
        int dp_max2=nums[1];
      
       
        for(int i=1;i<nums.length-1;i++){
            dp_i_2=dp_i_1;
            dp_i_1=dp_max1;
            if(dp_i_2+nums[i]>dp_i_1){
                dp_max1=dp_i_2+nums[i];
               
            }else{
                dp_max1=dp_i_1;
            }
        }
        
        
        dp_i_1=0;
        dp_i_2=0;
        for(int i=2;i<nums.length;i++){
            dp_i_2=dp_i_1;
            dp_i_1=dp_max2;
            if(dp_i_2+nums[i]>dp_i_1){
                dp_max2=dp_i_2+nums[i];

            }else{
                dp_max2=dp_i_1;
            }
        }
    
        return Math.max(dp_max1,dp_max2);

    }
}
```