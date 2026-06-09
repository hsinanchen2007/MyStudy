// ```
class Solution {
public:
	int jump(vector<int>& nums) {
		vector<int> stepMap;
		stepMap.push_back(0);
		for (int i = 0; i < nums.size(); i++) {
			int step = stepMap[i] + 1;
			int walk = nums[i];
			for (int j = stepMap.size(); j <= i + walk; j++) {
				stepMap.push_back(step);
			}
			if (stepMap.size() == nums.size())
				return stepMap[nums.size() - 1];
		}
		return stepMap[nums.size() - 1];
	}
};
// ```
// 一开始用DP，然后发现有个25000的测试用例在坑👴，想了想，发现没必要挨个比较min(dp[j], dp[j]-1)
// 同样用一个数组保存抵达位置n所需的最小步数，挨个遍历，能跳的更远就把多出来的位置push back进去，最后取出stepMap最后一个元素就是答案。
