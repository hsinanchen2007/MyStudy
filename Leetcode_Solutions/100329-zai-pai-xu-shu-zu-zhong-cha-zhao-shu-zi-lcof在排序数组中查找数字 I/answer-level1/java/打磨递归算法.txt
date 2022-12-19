### 解题思路
万物皆可递归系列，直接上代码，简单易懂

### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
        if(nums != null && nums.length != 0) {
			return searchRecursion(nums,0,nums.length-1,target);
		}
		return 0;
    }
    private static int searchRecursion(int[] nums, int left, int right, int target) {
		if(left > right) {
			return 0;
		}
		int mid = (left + right) >> 1;
		if(nums[mid] == target) {
			int toLeft = mid;
			int toRight = mid;
			int count = 0;
			while(toRight < nums.length && nums[toRight++] == target) {
				count++;
			}
			while(toLeft > 0 && nums[--toLeft] == target) {
				count++;
			}
			return count;
		}else {
			if(target > nums[mid]) {
				return searchRecursion(nums,mid + 1,right,target);
			}else {
				return searchRecursion(nums,left,right - 1,target);
			}
		}
	}
}
```