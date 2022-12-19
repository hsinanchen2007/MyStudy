执行结果 ：48 ms 击败了83.93%
          9.4MB 击败了73.78%

class Solution {
public:
	void threeSum(vector<int>& nums, int flagnum, int index, set<vector<int> >&ans, int target) {
		for (int i = index + 1; i < nums.size(); i++)
		{
			int str = i + 1, end = nums.size() - 1;
			while (end > str)
			{
				if (nums[i] + nums[str] + nums[end] > flagnum) end--;
				else if (nums[i] + nums[str] + nums[end] < flagnum) str++;
				else if (i != index && str != index && end != index)
				{
					vector<int> temp = { target - flagnum,nums[i],nums[str],nums[end] };   
                   if(ans.find(temp)==ans.end())
                   {
                       ans.insert(temp);
                   }
					end--;
					str++;
					while (str < end && nums[str] == nums[str - 1]) ++str;
					while (str < end && nums[end] == nums[end + 1]) --end;
				}
			}
		}
	}
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		set < vector<int> >ans1;
        vector<vector<int>>ans;
		if (nums.size() < 4)
		{
			return ans;
		}
		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size() - 3; i++)
		{
			threeSum(nums, -nums[i] + target, i, ans1, target);
		}
		for(auto  i=ans1.begin();i!=ans1.end();i++)
        {
            ans.push_back(*i);
        }
        return ans;
	}
};
