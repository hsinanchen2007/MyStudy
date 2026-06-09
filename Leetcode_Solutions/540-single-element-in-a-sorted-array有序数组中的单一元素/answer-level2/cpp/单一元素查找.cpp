题目条件有限制，导致这道题目变成了水题，只需要判断偶数位置上的数字是否与其位置上+1的元素相同就可以了，element_type是int。
class Solution {
public:
	int singleNonDuplicate(vector<int>& nums) {
		//找出只出现过一次的数字;
		//寻找偶数位置;
		for (int i = 0; i < nums.size(); i += 2) {
			if (i+1<nums.size()&&nums[i] != nums[i + 1]) return nums[i];
			else if (i + 1 >= nums.size()) {
				return nums[i];
			}
		}
		return -1;
	}
};