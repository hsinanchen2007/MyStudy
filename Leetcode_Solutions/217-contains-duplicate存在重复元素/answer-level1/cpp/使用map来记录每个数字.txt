```
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(auto n:nums)
        {
            if(st.count(n) > 0)
            {
                return true;
            }
            else
            {
                st.insert(n);
            }
        }
        return false;
    }
};
```
