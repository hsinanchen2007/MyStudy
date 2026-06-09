class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k)
    {
        int size = nums.size();
        if (size < 2) {
            return false;
        }

        for (int i = 0; i < size-1; i++) {
            int sum = nums[i];
            for (int j = i + 1; j < size; j++) {
                sum += nums[j];
                if (sum == k 
                || (k != 0 && sum % k == 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};