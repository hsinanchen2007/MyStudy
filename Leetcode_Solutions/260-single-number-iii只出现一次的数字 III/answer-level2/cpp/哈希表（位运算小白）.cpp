
### 代码

```cpp
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size()==2) return nums;

        vector<int> res;
        unordered_map<int,int> help;
        for(int num:nums) help[num]++;
        for(auto m:help) if(m.second==1) res.push_back(m.first);
        
        return res;
    }
};
```