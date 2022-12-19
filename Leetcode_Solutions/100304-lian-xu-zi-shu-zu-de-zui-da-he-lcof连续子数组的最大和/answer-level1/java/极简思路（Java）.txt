### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/c3846410bdc4b34e91bfa875444ba2ab706b42a95ac25e0cb5cdff7a88bc6db6-image.png)


### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {


         int[] currSum=new int[nums.length];
         
         int[] maxSum=new int[nums.length];

         int sum=Integer.MIN_VALUE;
         int cur=0;

         for(int i=0;i<nums.length;i++){
             
              
              cur=Math.max(cur+nums[i],nums[i]);
              
              if(cur>sum){
                  sum=cur;
              }


         }

         return sum;

    
}

}
```