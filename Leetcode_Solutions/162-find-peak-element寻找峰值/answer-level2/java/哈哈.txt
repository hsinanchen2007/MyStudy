### 解题思路
此处撰写解题思路
继续加油，寻找矩阵的最小值 ***
### 代码

```java
class Solution {
    public int findPeakElement(int[] nums) {
        int len = nums.length;
		int out = findEle(nums, 0, len-1);
		return out;
    }

    private int findEle(int[] nums, int i, int j) {
		//
		if(i == j)
			return i;
		
		while(i < j) {
			int mid = i + (j - i)/2;
			if(nums[mid] > nums[mid+1]) { //说明峰值在左边，并且包含nums[mid]
				return findEle(nums, i, mid);
			}else {
				return findEle(nums, mid + 1, j); //说明峰值在右边，不包含nums[mid]
			}
		}
		return i;
		
	}
}
```
![image.png](https://pic.leetcode-cn.com/6056a63d2fc236f3c8770e2702482d500a75151ab9a14b182c72993d6a74e4a8-image.png)
