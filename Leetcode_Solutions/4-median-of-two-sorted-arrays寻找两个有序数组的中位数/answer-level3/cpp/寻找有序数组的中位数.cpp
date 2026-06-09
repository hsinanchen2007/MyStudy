### 解题思路
此处撰写解题思路
在两个有序数组中，找出第k小数
然后分别在两个数组中取前k/2的数进行比较，舍弃较小的部分
剩下m+n-k/2的数中，寻找第k-k/2小的数
### 代码

```cpp
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int total = nums1.size() + nums2.size();
		if (total % 2 == 1) {
			// 数字个数为奇数
			return FindNum(nums1, 0, nums2, 0, (total + 1) / 2);
		}
		else{
			// 数字个数为偶数
			int left = FindNum(nums1, 0, nums2, 0, (total) / 2);
			int right = FindNum(nums1, 0, nums2, 0, (total) / 2 + 1);
			return (left + right) / 2.0;
		}
	}

	int FindNum(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
		// nums1的长度要求小于nums2
		// i：nums1数组中nums1[i]到数组结束的部分参与比较
		// j：nums2数组中nums2[j]到数组结束的部分参与比较
		// k：在两个数组参与比较的部分中，寻找第k小的数
		// 递归结束的条件：k = 1，寻找第1小的数，返回两个数组参与比较部分的最小数
		// 当一个数组没有所有元素都被舍弃，则从第二个数组直接寻找第k小的数
		if (nums1.size() - i > nums2.size() - j)
			return FindNum(nums2, j, nums1, i, k);
		if (nums1.size() == i)
			return nums2[j + k - 1];
		if (k == 1)
			return min(nums1[i], nums2[j]);
		int si = min(int(nums1.size()), i + k / 2), sj = j + k / 2;
		// 比较第k/2 - 1 小的数
		if (nums1[si - 1] > nums2[sj - 1]) {
			return FindNum(nums1, i, nums2, sj, k - k / 2);
		}
		else{
			return FindNum(nums1, si, nums2, j, k - (si - i));
		}
	}
};
```