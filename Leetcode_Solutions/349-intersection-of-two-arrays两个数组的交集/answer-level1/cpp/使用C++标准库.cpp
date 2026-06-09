```
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        vector<int> v(nums1.size());
        auto it = std::set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), v.begin());
        v.resize(it - v.begin());
        it = std::unique(v.begin(), v.end());
        v.resize(it - v.begin());
        return v;
    }
};
```
