class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto iter = find(nums.begin(), nums.end(), target);
        if(iter != nums.end()){
            return iter - nums.begin();
        }else
            return -1;
    }
};