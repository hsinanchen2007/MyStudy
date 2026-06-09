```
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> st;
        vector<int> ret;
        set<int> st2;
        for (auto n:nums1)
        {
            st.insert(n);
        }
        for (auto n:nums2)
        {
            if(st.count(n)>0 && st2.count(n) == 0)
            {
                ret.push_back(n);
                st2.insert(n);
            }
        }
        return ret;
    }
};
```
