class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> hashset;
        for(int i = 0; i < nums.size(); i++)
        {
            if (hashset.find(nums[i]) != hashset.end()) return true;
            hashset.insert(nums[i]);
            if (hashset.size() > k) hashset.erase(nums[i-k]);         
        }
        return false;

    }
};