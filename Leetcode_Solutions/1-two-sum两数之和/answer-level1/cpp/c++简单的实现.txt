### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int i=0;i<nums.size();i++)
        {
                 for (int j = i + 1; j < nums.size(); j++)
                    {
                        if(nums[i]+nums[j] == target)
                        {
                            result.push_back(i);
                            result.push_back(j);
                             return result;
                        }
                      
                    }
        }
        return result;
    }
};
```
