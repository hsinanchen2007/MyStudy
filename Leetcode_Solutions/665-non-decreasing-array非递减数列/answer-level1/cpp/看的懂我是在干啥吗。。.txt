class Solution {
public:
	bool checkPossibility(vector<int>& nums) {
		int wrongNum = 0;
		for (int i = 0; i < nums.size()-1; i++)
		{
			if (nums[i] > nums[i + 1])
			{
				wrongNum++;
				bool modifynextfail = (i + 2 <= nums.size() - 1) && (nums[i] > nums[i + 2]);
				bool modifycurfail = (i > 0) && (nums[i - 1] > nums[i + 1]);
				wrongNum += modifynextfail && modifycurfail;
			}
		}
		return wrongNum <= 1 ;
	}
};


我不想解释了，正确的，时间复杂度O(N)))
不信你拿去跑。。。