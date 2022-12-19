```
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.size() ==0)
        {
            return -1;
        }
        else
        {
            int sum = 0;
            int sum_left = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                sum = sum + nums[i];
            }

            for (int j = 0; j < nums.size(); j++)
            {
                if (sum_left*2 == sum-nums[j])
                {
                    return j;
                }
                sum_left += nums[j];
            }
            return -1;
        }
    }
};

```

解题思路：
1. 首先确定，中心索引的定义为，一个数组左边元素和与右边元素和相等
2. 由 1. 明确，两倍的左边索引之和等于数组所有元素和减去中心索引的值


