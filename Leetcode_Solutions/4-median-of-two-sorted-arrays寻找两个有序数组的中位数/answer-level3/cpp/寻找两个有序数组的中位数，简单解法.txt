### 解题思路
此处撰写解题思路
**1.空值处理**
首先如题中最后假设两个数组不会同时为空，所以先考虑其中之一为空的特殊情况。
由于s1和s2都是有序数组，假如nums1为空，那么中位数就是s2最中间的那个值。
假如s2的size为奇数，易求得中位数就是迭代器 nums2.begin() + nums2.size() / 2 所指的值，偶数同理可推。
如果是nums2为空，则直接递归调用交换两个实参即可。

**2.示例2所示情况**
如题目示例显示了两种情况，显然示例2更为特殊，数组s2中所有元素顺序都在s1的后面，这种情况更容易处理。
为了方便处理，将两个数组中，第一个数更小者定为s1，另一个即为s2.同样也是通过递归调用实现这一点。

之后就想象把s1和s2拼接起来，显然中位数的所在位置与s1、s2的大小有关。
以s1较小为例，那么中位数就在s2中。具体的位置可以通过(s1.size+s2.size)/2-s1.size计算出来

**3.示例1所示情况**
显然有一种暴力解法是将s1、s2全部push_back到一个新数组里，然后给新数组排序，再用类似1.中的办法找中位数
但是这就没有利用到s1、s2本身的有序性，肯定不是个好方法。

如果使用两个指针A、B分别指向s1和s2的第一个元素，执行一个循环，每次循环都判断一下A和B所指元素的相对大小，将较小者加入新数组，同时把指针移到下一个元素。
每次循环还都判断一下新数组的大小是否达到了s1和s2大小之和的一半，如果达到了，立刻退出循环。
根据s1和s2大小之和的奇偶性，分别处理。例如是奇数，那么新数组的最后一个元素即是中位数。

### 代码

```cpp
class Solution {
public:
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {


	int s1 = nums1.size(), s2 = nums2.size(), sSum = s1 + s2;

	if (s1 == 0)
	{
		if (s2 % 2 == 0)
		{
			return (*(nums2.begin() + s2 / 2) + *(nums2.begin() + s2 / 2 - 1)) / 2.0;
		}
		else
			return *(nums2.begin() + s2 / 2);
	}
	else if (s2 == 0)
		return findMedianSortedArrays(nums2, nums1);

	auto begin1 = nums1.begin(), begin2 = nums2.begin();
	auto end1 = nums1.end() - 1, end2 = nums2.end() - 1;

	int L1 = *begin1, L2 = *begin2, R1 = *end1, R2 = *end2;

	if (L1 > L2)
		return findMedianSortedArrays(nums2, nums1);

	bool IsEven;
	if (sSum % 2 == 0)
		IsEven = 1;
	else
		IsEven = 0;

	////
	if (R1 <= L2)
	{
		if (s1 == s2)
			return (R1 + L2) / 2.0;
		else if (s1 < sSum / 2+1)
		{
			if (IsEven == 0)
				return *(begin2 + (sSum / 2 - s1));
			else
				return (*(begin2 + (sSum / 2 - s1) - 1) + *(begin2 + (sSum / 2 - s1))) / 2.0;
		}
		else
		{
			if (IsEven == 0)
				return *(end1 - (sSum / 2 - s2));
			else
				return (*(end1 - (sSum / 2 - s2)) + *(end1 - (sSum / 2 - s2) + 1)) / 2.0;
		}

	}
	////
	else
	{
		vector<int> numsum;
		while (numsum.size() < sSum / 2.0 + 0.5)
		{
			if (begin1 == nums1.end())
				numsum.push_back(*begin2++);
			else if(begin2 == nums2.end())
				numsum.push_back(*begin1++);
			else if (*begin1 <= *begin2)
				numsum.push_back(*begin1++);
			else
				numsum.push_back(*begin2++);
		}
		if (IsEven == 0)
			return *(numsum.end() - 1);
		else
			return (*(numsum.end() - 1) + *(numsum.end() - 2)) / 2.0;
	}
}
};
```