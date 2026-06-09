### 解题思路
看了题解大佬的思路自己仿照学习了一遍

### 代码

```cpp
class Solution {

public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		//保证nums1短于nums2
		if (nums1.size() > nums2.size()) {
			return findMedianSortedArrays(nums2, nums1);
		}

		int size1 = nums1.size(), size2 = nums2.size(), LMax1, RMin1, LMax2, RMin2, c1, c2, lo = 0, hi = 2 * size1;
		while (lo<=hi) {
			c1 = (lo + hi) / 2;
			c2 = size1 + size2 - c1;
			LMax1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
			RMin1 = (c1 == 2 * size1) ? INT_MAX : nums1[c1 / 2];
			LMax2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
			RMin2 = (c2 == 2 * size2) ? INT_MAX : nums2[c2 / 2];
			if (LMax1 > RMin2) {
				hi = c1 - 1;
			}
			else if (LMax2 > RMin1) {
				lo = c1 + 1;
			}
			else {
				break;
			}
		}
		return static_cast<double>(max(LMax1, LMax2) + min(RMin1, RMin2)) / 2;
	}
};
```