### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int len = nums.length;
        int[] sum = new int[len];
        int[] num = new int[len];
        sum[0]=1;num[len-1]=1;
        for(int i = 1; i < len; i++)
        	sum[i]=nums[i-1]*sum[i-1];
       for(int i=len-2;i>=0;i--)
         num[i]=nums[i+1]*num[i+1];
         for(int i=0;i<len;i++)
             sum[i]*=num[i];
       	return sum;
    }
}
```