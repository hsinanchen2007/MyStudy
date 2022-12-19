## 思路
同时比较两个数组nums1和nums2中最大的数，把最大的数放在m+n-1的位置，然后位置-1，最大数所在数组位置-1，继续比较，直到nums2遍历完成。

## 实现
```
class Solution {
	public void merge(int[] nums1, int m, int[] nums2, int n) {
		int pos = m + n - 1;
		while (n > 0) {
			if (m > 0 && nums1[m - 1] > nums2[n - 1]) {
				nums1[pos--] = nums1[--m];
			}else {
				nums1[pos--] = nums2[--n];
			}
		}
	}
}
```