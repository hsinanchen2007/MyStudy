### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
   public double findMedianSortedArrays(int[] nums1, int[] nums2) {
		if (nums1 == null && nums2 == null) {
			return 0d;
		}
		if (nums1 == null) {
			return nums2.length % 2 == 0 ? (nums2[nums2.length / 2] + nums2[nums2.length / 2 - 1]) / 2.0
					: nums2[nums2.length / 2];
		}
		if (nums2 == null) {
			return nums1.length % 2 == 0 ? (nums1[nums1.length / 2] + nums1[nums1.length / 2 - 1]) / 2.0
					: nums1[nums1.length / 2];
		}
		int len1 = nums1.length;
		int len2 = nums2.length;
		int mergeLen = len1 + len2;
		nums1 = Arrays.copyOfRange(nums1, 0, mergeLen);
		System.arraycopy(nums2, 0, nums1, len1, len2);
		Arrays.sort(nums1);
		return mergeLen % 2 == 0 ? (nums1[mergeLen / 2] + nums1[mergeLen / 2 - 1]) / 2.0 : nums1[nums1.length / 2];
	}
}
```