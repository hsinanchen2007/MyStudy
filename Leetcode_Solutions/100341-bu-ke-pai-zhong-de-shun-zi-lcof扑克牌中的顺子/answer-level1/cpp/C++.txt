```cpp
class Solution {
public:
    bool isStraight(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int balance = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == 0) balance++;
            else if (nums[i] == nums[i + 1])
                return false;
            else
                balance -= (nums[i + 1] - nums[i] - 1);
        }
        return balance >= 0;
    }
};

```