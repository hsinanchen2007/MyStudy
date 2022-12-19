### 解题思路
主要就是用到数组的互换操作，前后位置移动关系

### 代码

```java
class Solution {
    public void moveZeroes(int[] nums) {
        int lastIndex = 0;//定义个临时的变量，用于存储上次为0的索引
		 int len = nums.length;
		 for(int i = 0;i < len;i++) {
			 if(nums[i] != 0) {//遍历每个数字，如果不为0,则需要向前移动
				 nums[lastIndex] = nums[i];//使用经典的位置互换代码
				 if (lastIndex != i) {
					 nums[i] = 0;//不相等的时候，设置为0
	             }
				 lastIndex++;//索引加1
			 }
		 }
    }
}
```