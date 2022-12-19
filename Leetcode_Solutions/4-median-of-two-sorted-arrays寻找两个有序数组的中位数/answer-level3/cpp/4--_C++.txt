### 代码

```cpp
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size();
		int m = nums2.size();//两个数组的元素个数
		if (n > m)
			return findMedianSortedArrays(nums2, nums1);//选择元素较少的数组效率会更高

		int LMax1, LMax2, RMin1, RMin2;//用来标记两数组的中位数附近值
		int c1, c2, lo = 0, hi = 2 * n;//将nums1扩大，目前元素个数2n+1
		while (lo <= hi)//二分
		{
			c1 = (lo + hi) / 2;//对nums1数组二分
			c2 = m + n - c1;//这里是因为我们选择的中位数的数组目前大小已变为2*(m+n+1),我们需要c1+c2=m+n;

			LMax1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
			RMin1 = (c1 == 2 * n) ? INT_MAX : nums1[c1 / 2];
			LMax2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
			RMin2 = (c2 == 2 * m) ? INT_MAX : nums2[c2 / 2];

			if (LMax1 > RMin2)
				hi = c1 - 1;
			else if (LMax2 > RMin1)
				lo = c1 + 1;
			else
				break;
		}
		return (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0;
	}
};
```