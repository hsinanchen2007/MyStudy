### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto n:nums) mp[n]++;
        for(auto m:mp){
            if(m.second>1) return m.first;
        }
        return 0;
    }
};
```