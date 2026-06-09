### 解题思路
使用双指针法，一个在前面，一个在后面来进行这个操作

### 代码

```java
class Solution {
    public boolean containsDuplicate(int[] nums) {
        		//排序
        if(nums.length==0){
            return false;
        }
		Arrays.sort(nums);
		//如果
		int i=0,j;
		for (j = 1; j < nums.length; j++,i++) {
			if(nums[i]==nums[j]) {
				return true;
			}
		}
		if(j==nums.length) {
			return false;
		}
		return true;


    }
}
```