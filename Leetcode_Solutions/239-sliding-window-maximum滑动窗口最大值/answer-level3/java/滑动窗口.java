### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int []p=new int[0];
        if(nums.length==0)
         return p;
        int max=-2147483648,x=0;
        int []sum=new int[nums.length-k+1];
        for(int i=0;i<nums.length-k+1;i++){
            max=-2147483648;
            for(int j=i;j<i+k;j++){
               if(nums[j]>max)
               max=nums[j];
            }
           sum[x++]=max;
        }
        return sum;
    }
}
```