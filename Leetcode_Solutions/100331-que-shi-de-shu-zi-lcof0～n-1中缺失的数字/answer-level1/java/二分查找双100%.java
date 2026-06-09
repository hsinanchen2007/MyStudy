### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int missingNumber(int[] nums) {
        if(nums==null || nums.length==0) 
			return -1;
		return searchMissing(nums, 0, nums.length-1);
    }
    public static int searchMissing(int [] nums,int l,int r) {
		int mid=(l+r)>>>1;
		if(l==r && l==nums[l]) {
			return nums[r]+1;
		}
		if(l==r && nums[l]>l) {
			return nums[r]-1;
		}
		if(nums[mid]==mid) {
			return searchMissing(nums, mid+1, r);
		}else {
			return searchMissing(nums, l, mid);
		}
			
	}
}
```