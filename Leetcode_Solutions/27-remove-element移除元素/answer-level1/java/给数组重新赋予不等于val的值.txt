### 解题思路
此处撰写解题思路
两个索引，一个查找不等于val的值，一个用来标记数组下标
### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        if(nums.length == 0)
			return 0;
		int index = 0;
		int i =0;
		int count = 0;
		while(index<nums.length) {
			if(nums[index] != val) {
				nums[i] = nums[index];
				i++;
				index++;
				count++;
			}else {
				index++;
			}
		}
		return count; 
	}
    }
```