### 解题思路
针对nums中的每个x利用map查找target - x

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            if(mp.count(target - nums[i])){
                result.push_back(mp[target - nums[i]]);
                result.push_back(i);
            }
            else
                mp[nums[i]]=i;
        }
        return result;
    }
};
```