### 解题思路
用哈希表

### 代码

```cpp
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        map<int, int>hash;
        vector<int> result;
        for(int i=0;i<nums.size();i++)
        {
            auto iter = hash.find(nums[i]);
            if(iter==hash.end())
                hash[nums[i]]=nums[i];
            else
                hash.erase(iter);
        }
        for(auto iter=hash.begin();iter!=hash.end();iter++)
        {
            result.push_back(iter->second);
        }
        return result;
    }
};
```