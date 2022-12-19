![2020010501.PNG](https://pic.leetcode-cn.com/d5049c57077f89324a59464521549fe4cb2c55b050cfc20da58e05a2e2aecea9-2020010501.PNG)

### 解题思路
思想:每次均只移动最大值,目的是使较小值一直处于加1的状态;
利用上述思想,经归纳总结得到数学规律---移动的最小次数为:(数组中的各个值-数组中最小值)的总和;
所以,首先遍历一遍数组,找到数组的最小值(minValue),
其次,再遍历一遍数组,计算数组中各个值与最小值(minValue)之差的总和out(声明out记录和),返回out即可

### 代码

```java
class Solution {
    public int minMoves(int[] nums) {
        int minValue = Integer.MAX_VALUE;
    	int out = 0;
		//遍历一遍数组找到z数组中的最小值minValue
    	for(int i=0;i<nums.length;i++) {
    		if(nums[i]<minValue) {
    			minValue = nums[i];
    		}
    	}
		//再遍历一遍数组,计算各个值与最小值之差的总和
    	for(int i=0;i<nums.length;i++) {
    		out = out + (nums[i]-minValue);
    	}
    	return out;
    }
}
```