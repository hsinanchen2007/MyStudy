```
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> vec;
        set<int> st1(nums1.begin(), nums1.end());
        set<int> st2(nums2.begin(), nums2.end());

        for (auto s:st1) {
            if (st2.count(s))
                vec.emplace_back(s);
        }
        return vec;
    }
};
```
