最容易想到的方法：四数之和->三数之和->两数之和
  vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int> > temp;
        vector<vector<int> > result;

        int last = INT_MAX;
        for (int i = nums.size() - 1; i > 2; i--)
        {
            while (i != nums.size()-1 && i >= 0 && nums[i] == nums[i + 1])
            {
                i--;
            }
            if (i <= 2)
                break;
            last = nums[i];
            //nums.pop_back();
            vector<int> segment(nums.begin(), nums.begin()+i);
            int target1 = target - last;
            if (segment.size() >= 3)
                temp = threeSum(segment, target1);
            for (int i = 0; i < temp.size(); i++)
            {
                temp[i].push_back(last);
                result.push_back({ temp[i][0], temp[i][1], temp[i][2], temp[i][3] });
            }
            temp.clear();
        }
        return result;
    }

