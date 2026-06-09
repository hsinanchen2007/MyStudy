### 解题思路
此题主要思路是快排或堆排。但是性能上快排或堆排并非在所有数据量情况下都为最佳处理方案。
直接考虑使用vector的排序算法，会根据传入数据量多少确认最佳排序方案。

答案取巧。用了Stl的标准库函数。

### 代码

```cpp
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
	double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
		int iLength = nums1.size() + nums2.size();
		std::vector<int> vecTemp(iLength);

		std::copy(nums1.begin(), nums1.end(), vecTemp.begin());
		std::copy(nums2.begin(), nums2.end(), vecTemp.begin() + nums1.size());

		std::sort(vecTemp.begin(), vecTemp.end());
		double dResult = 0.0;
		if (iLength % 2 == 0)
		{
			dResult = (vecTemp[(iLength / 2) - 1 ] + vecTemp[(iLength / 2)]) * 1.0 / 2;
		}
		else
		{
			dResult = vecTemp[iLength / 2] ;
		}
		
		return dResult;
	}
};
```