### 解题思路
题目已经告知：如果数组长度为n，那么数组中元素的范围即为0~n-1
所以排序后的元素i也应该在i位置
遍历数组，如果元素i不在位置i，那么就将其与位置i的元素交换；
如果位置i的元素已经是元素i，说明重复

### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
     for(int i=0;i<nums.length;i++){
	if(nums[i]!=i){
		int temp = nums[nums[i]];
		if(nums[i]==temp)
			return nums[i];
		else{
			nums[nums[i]]=nums[i];
			nums[i]=temp;
		}
	}
}
return -1;

    }
}
```