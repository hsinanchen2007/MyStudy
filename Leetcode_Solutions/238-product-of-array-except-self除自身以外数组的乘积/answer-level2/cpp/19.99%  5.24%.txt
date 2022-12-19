### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size() < 1) return {};
        int total = 1;
        vector<int> zeroPos;
        int num;
        for(auto i = 0; i < nums.size(); i++)
        {
            num = nums[i];
            if(num == 0)
            {
                zeroPos.push_back(i);
                if(zeroPos.size() > 1)
                {
                    break;
                }
            }
            else
            {
                total *= num;
            }
        }

        vector<int> mulNums;
        for(auto num : nums)
        {
            if(zeroPos.size() == 1)
            {
                if(num == 0)
                {
                    mulNums.push_back(total);
                }
                else
                {
                    mulNums.push_back(0);
                }
            }
            else if (zeroPos.size() > 1)
            {
                mulNums.push_back(0);
            }
            else
            {
                mulNums.push_back(total / num);
            }
        }

        return mulNums;
    }
};
```