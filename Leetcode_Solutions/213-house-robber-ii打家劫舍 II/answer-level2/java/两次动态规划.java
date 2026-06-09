### 解题思路
两次动态规划

### 代码

```java
class Solution {
    public int rob(int[] nums) {
       int a=0,b=0;
       int i,c;
       if(nums.length==0)
            return 0;
       if(nums.length==1)
            return nums[0];
       for(i=0;i<nums.length-1;i++)
            {c=Math.max(b,a+nums[i]);
            a=b;
            b=c;}
        int sum1=b;
        b=0;a=0;
        for(i=1;i<nums.length;i++)
            {c=Math.max(b,a+nums[i]);
            a=b;
            b=c;}
        int sum2=b;
        return (sum1>sum2)?sum1:sum2;
    }
}
```