```
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        unordered_map<int, int> mp2;
        stack<int> st2;
        unordered_map<int, int>::iterator iter;
        for(auto n:nums2)
        {
            while(!st2.empty() && n>st2.top())
            {
                mp2[st2.top()] = n;
                st2.pop();
            }
            st2.push(n);
        }
        for(auto n:nums1)
        {
            iter = mp2.find(n);
            ret.push_back(iter==mp2.end() ? -1 : iter->second);
        }
        return ret;
    }
};
```
