### 解题思路
将两个有序数组按序存放在一个新数组中，再根据奇偶性计算中位数。

### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {

		int[] nums = new int[nums1.length + nums2.length];
		int i = 0;
		int j = 0;
		int k = 0;
		
		while (true) {
			if (i == nums1.length)
				break;
			if (j == nums2.length)
				break;
			nums[k++] = (nums1[i] < nums2[j]? nums1[i++] : nums2[j++]);
		}
		
		while (i < nums1.length) {
			nums[k++] = nums1[i++];
		}
		while (j < nums2.length) {
			nums[k++] = nums2[j++];
		}
		
		if (nums.length % 2 == 0) {
			return ((double)nums[nums.length / 2 - 1] + nums[nums.length / 2]) / 2;
		}
		else {
			return (double)nums[nums.length / 2];
		}

    }
}
```