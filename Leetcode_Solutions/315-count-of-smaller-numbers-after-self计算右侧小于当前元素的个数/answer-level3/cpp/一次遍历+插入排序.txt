class Solution {
public:
    void InsertSort(vector<int>& nums, vector<int>& result, int index, int value)
    {
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (value > nums[i]) {
                nums.insert(nums.begin() + i + 1, value);
                result[index] = i + 1;
                return;
            }
        }
        nums.insert(nums.begin(), value);
        result[index] = 0;
    }
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        int count = 0;
        vector<int> result(nums.size(), 0);
        vector<int> tempNums;
        tempNums.push_back(nums[nums.size() - 1]);
        for (int i = nums.size() - 2; i >= 0; --i) {
            InsertSort(tempNums, result, i, nums[i]);
        }
        return result;
    }
};