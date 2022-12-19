```c++
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int max_reach = nums[0];
        for (int i = 1; i <= max_reach && i < nums.size(); ++i)
            if (max_reach < nums[i] + i)
                max_reach = nums[i] + i;
        return max_reach >= int(nums.size()) - 1;
    }
};
```