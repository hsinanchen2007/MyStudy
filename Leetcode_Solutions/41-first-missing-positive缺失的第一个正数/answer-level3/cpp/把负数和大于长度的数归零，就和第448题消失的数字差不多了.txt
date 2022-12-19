思路：第一个未出现的数字，和数组中的负数、0无关，对于数值比数组长度还大的数字，也无关，因为结果必然比它小，
那么把两类数字改为0之后，数组中的数字就在区间[0,len]上了，这就和[第448题，消失的数字](https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array)差不多了，用数组下标上的数字是否大于len来表示该坐标对应的数字是否存在，只要找到第一个不存在的就是答案。
```
class Solution {
public:
	int firstMissingPositive(vector<int> nums) {
		int len = nums.size(), res = 1;
		if (len == 0)return res;
    int helper=len+1;
		for (auto& n : nums) {
			if (n > len || n < 0)
				n = 0;
		}
		for (auto& n : nums) {
			int cur = n % helper;
			if (cur>0)nums[cur - 1] += helper;
		}
		int i = 0;
		while (i < len && nums[i] >= helper)++i;
		return i + 1;
	}
};
```
