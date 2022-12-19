### 解题思路
![image.png](https://pic.leetcode-cn.com/32a638175a27900f13ca21286a62518dd830ab135d822d885243d6149c1deae7-image.png)


### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {


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