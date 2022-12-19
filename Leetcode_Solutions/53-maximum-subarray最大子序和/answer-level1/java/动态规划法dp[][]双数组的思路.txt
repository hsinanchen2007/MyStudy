### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
     public   int maxSubArray(int[] nums) {
		   if(nums.length == 0) {
			   return 0;
		   }  
		   int leng = nums.length;
		   int[] pre = new int[leng + 1];
		   int[] cur = new int[leng + 1];
		   
		   int[] tmp;
		   int max = nums[0];
		   for(int i = 1 ; i <= leng ; i ++ ) {
			   for(int j = 1 ; j <= i ; j ++ ) {
				   cur[j] = pre[j-1] + nums[i-1];
				   max = Math.max(cur[j], max);
			   }
			   tmp = pre;
			   pre = cur;
			   cur = tmp;
		   }
		   
		   return max;
	    }
}
```