### 二分查找
1. 如果除数取1时，商的和都要比阈值小，则直接返回1，这已经是最小的正整数了
2. 二分查找最小除数
	 - 最小左值`l`取1；最大右值`r`取`nums`中最大值
	 - 计算以中间值`mid = (l + r) / 2`为除数的商的和
	 - 如果和比阈值大，则左边界增大，`l`取值为`mid+1`；否则减小右边界，`r`取值为`mid`
	 - 最终左右边界重叠时即为最小除数解
```
class Solution {
public:
	int smallestDivisor(vector<int>& nums, int threshold) {
		if (compareDivisionSum(nums, threshold, 1) <= 0)
			return 1;

		int nMaxNum = 0;
		for (size_t i = 0; i < nums.size(); ++i)
			nMaxNum = std::max(nMaxNum, nums[i]);
		if (threshold <= 0)
			return nMaxNum + 1;

		int l = 1, r = nMaxNum;
		while (l < r) {
			int mid = (l + r) / 2;
			int nCompare = compareDivisionSum(nums, threshold, mid);
			if (nCompare > 0)
				l = mid + 1;
			else
				r = mid;
		}

		return l;
	}

	// 比较阈值和商的和；如果商的和比阈值大则返回1；比阈值小则返回-1；等于阈值则返回0
	int compareDivisionSum(const vector<int>& nums, int threshold, int divisor) {
		int nSum = 0;
		for (size_t i = 0; i < nums.size(); ++i) {
			nSum += nums[i] / divisor + (nums[i] % divisor != 0);
			// 这样子做就不用考虑和会溢出的问题了
			if (nSum > threshold)
				return 1;
		}

		return (nSum == divisor) ? 0 : -1;
	}
};
```
我果真不适合写题解，写文章啊！