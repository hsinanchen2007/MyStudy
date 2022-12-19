### 解题思路
找到第k小的数，比如left与right分别的指向可计算中位数的位置
程序采用尾递归的形式，递归出口有两个，一个是k=1，一个是len1 or len2等于0
对k进行二分法
### 代码

```cpp
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size();
		int n = nums2.size();
		int left =  (m + n + 1) / 2;
		int right = (m + n + 2) / 2;
		return (findMedian(nums1,0,m-1,nums2,0,n-1,left)+ findMedian(nums1, 0, m - 1, nums2, 0, n - 1, right))/2.0;
	}
	double findMedian(vector<int>& nums1, int start1, int end1, vector<int>& nums2, int start2, int end2, int k){

		int len1 = end1 - start1 + 1;
		int len2 = end2 - start2 + 1;

		if (len1 > len2) {
			findMedian(nums2, start2, end2, nums1, start1, end1, k);
		}
		if (len1 == 0) {
			return nums2[start2 + k - 1];
		}
		if (len2 == 0) {
			return nums1[start1 + k - 1];
		}
		if (k == 1) {
			return min(nums1[start1],nums2[start2]);
		}
		int i = start1 + min(len1, k / 2) - 1;//min(len1, k / 2)保证在k/2大于数组长度时，i指向数组的最后
		int j = start2 + min(len2, k / 2) - 1;
		if (nums1[i] > nums2[j]) {
			return findMedian(nums1, start1, end1, nums2, j + 1, end2, k - (j - start2 + 1));//j+1体现二分法，用j - start2 + 1是因为要考虑到k/2大于数组长度的情况
		}
		else {
			return findMedian(nums1, i + 1, end1, nums2, start2, end2, k - (i - start1 + 1));
		}
	}
};
```