```
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end());
        vector<int> res;
        for_each(s1.begin(), s1.end(), [&s2, &res](int i){
            if (s2.count(i) > 0) res.push_back(i);
        });
        return res;
    }
};
```
