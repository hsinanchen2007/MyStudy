### 解题思路
暴力遍历所有可能

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,j;
        vector<int> s;
        for (i=0;i<nums.size()-1;i++){
            for(j=i+1;j<nums.size();j++)
            {
                if (target==(nums[i]+nums[j]))
               {
                    s.push_back(i);
                s.push_back(j);
                break;
               }   
            }
        }
        return s;
    }
};
```