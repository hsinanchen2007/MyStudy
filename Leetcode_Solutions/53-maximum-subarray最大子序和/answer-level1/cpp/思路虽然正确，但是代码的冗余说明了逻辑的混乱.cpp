### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int val = 0;
        int max = INT_MIN;
        int index;
        for(int i=0; i< nums.size(); i++)
        {
            max = (max > nums[i]) ? max : nums[i];
            if(nums[i] > 0)
            {
                val = nums[i];
                index = i + 1;
                break;
            }
        }
        if(val == 0 || index == nums.size()) return max;

        while(index < nums.size())
        {
            if(nums[index] + val > 0)
            {
                max = ((nums[index] + val) > max) ? (nums[index] + val) : max;
                val = nums[index] + val;
                index++;
            }
            else
            {
                int i = index + 1;
                for(i; i< nums.size(); i++)
                {
                    if(nums[i] > 0)
                    {
                        max = (max > nums[i]) ? max : nums[i];
                        val = nums[i];
                        break;
                    }
                } 
                index = i + 1;
            }
        }
        return max;
    }
};
```