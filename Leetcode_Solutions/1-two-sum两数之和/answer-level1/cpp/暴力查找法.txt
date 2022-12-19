### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int temp = 0;
        vector<int> v;
        for(auto i = 0; i < nums.size(); i++)
        {
            temp = target - nums[i];
            for(auto j = i + 1; j < nums.size(); j++)
            {
                if(temp - nums[j] == 0)
                {
                    v.push_back(i);
                    v.push_back(j);
                    return v;
                }
            }
        }
        return v;
    }
};
```