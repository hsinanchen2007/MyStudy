### 解题思路
AC一题 二分查找法

### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        int left = 0;
		int right = nums.length-1;
		while(left <= right) {
			int mid = left + (right - left) / 2;
			if(nums[mid] == target) {
				return mid;
			}else if(nums[mid] > target) {
				right = mid - 1;
			}else {
				left = mid + 1;
			}
		}
		return left;	
    }
}
```
![image.png](https://pic.leetcode-cn.com/80bdc1ec83f306e5b04dd5d93b4eb21bfde467cf1926a693e4c37f8a0c3dc0e4-image.png)
