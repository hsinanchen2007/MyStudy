### 解题思路
![1585840966(1).png](https://pic.leetcode-cn.com/ef46e45d0c85b3d00caa625fb665279a82127fcf8add4c3b51fb5170e844b7fb-1585840966\(1\).png)


### 代码

```java
class Solution {
    public int minSubArrayLen(int s, int[] nums) {
    	int len=nums.length;
    	int sum0=0;
    	for (int i = 0; i < nums.length; i++) {
			sum0+=nums[i];
		}
        if (sum0<s) return 0;
    	int sum=0, res=nums.length , left=0, right=0; 
    	while(left<len && right<len){
    	   int l=nums[left], r=nums[right];
    	   while(sum<s && right<len ){
    		   sum+=nums[right++];
    	   }
    	   while(sum>=s && left<len){
        	   res=Math.min(res, right-left);
    		   sum-=nums[left++];
    	   }     		
    	}
		return res;
    }
}
```