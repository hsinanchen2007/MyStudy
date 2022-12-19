### 解题思路
记录子数组的和，与当前最大值比较，如果子数组为负，将和归0
![QQ截图20200218235307.png](https://pic.leetcode-cn.com/ab858dea7d502b61b5add75dc7af69af768ef881653b5f1efafaed93a48b475d-QQ%E6%88%AA%E5%9B%BE20200218235307.png)


### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
       int sum = 0;
    	int max=Integer.MIN_VALUE;
    	for(int i = 0; i < nums.length; i++)
    	{
    		sum+=nums[i]; 	//sum加上当前值
    	    if(sum > max)	//与max比较
    			max = sum;
            if(sum < 0)		//如果sum < 0,则归0，注意：这两步if顺序是不可以换的，否则无法通过全是负数的输入
                sum= 0;
    	}
        return max; 
    }
}
```