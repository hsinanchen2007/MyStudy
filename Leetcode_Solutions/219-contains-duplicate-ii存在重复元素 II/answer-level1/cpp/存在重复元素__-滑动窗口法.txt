此题最关键的是题目的解析：
    给定数组nums和常数k，存在不同的i、j使得nums[i] = nums[j]，且abs(i-j) <= k。

    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> set; //搜索、插入和移除平均常数时间复杂度，不会超时
        for(int i = 0; i < nums.size(); i++)
        {
            if(set.find(nums[i]) != set.end())
                return true;
            set.insert(nums[i]);
            if(set.size() > k )
                set.erase(nums[i-k]); //滑动窗口长度最大为k 
        }
        return false;
    }