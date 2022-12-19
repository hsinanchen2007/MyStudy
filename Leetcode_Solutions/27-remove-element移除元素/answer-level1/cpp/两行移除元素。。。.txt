class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>::iterator ite = remove(nums.begin(), nums.end(), val);
        return ite - nums.begin();
    }
};