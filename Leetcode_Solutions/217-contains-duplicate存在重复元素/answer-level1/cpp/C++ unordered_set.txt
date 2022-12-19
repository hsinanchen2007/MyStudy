```
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> bobo;
        for(auto i:nums)
        {
            if(bobo.count(i)) return true;
            else bobo.insert(i);
        }
        return false;
    }
};
```
