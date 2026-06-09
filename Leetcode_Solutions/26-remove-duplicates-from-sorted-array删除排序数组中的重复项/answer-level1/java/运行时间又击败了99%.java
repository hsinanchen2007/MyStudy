### 解题思路
运行时间又击败了99%

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        int start = 0 , result = 0;
		int len = nums.length;
		if(len == 0 || len == 1) {
			return len;
		}
		while(start < len) {
			//已经跳过了重复数，这里可以直接复制就行。
			int num = nums[start];
			nums[result] = num;
			result++;
			//跳过重复书
			start = start + 1;
			while(start < len) {
				if(nums[start] != num) {
					break;
				}else {
					start++;
				}
			}
		}
		return result;
    }
}
```