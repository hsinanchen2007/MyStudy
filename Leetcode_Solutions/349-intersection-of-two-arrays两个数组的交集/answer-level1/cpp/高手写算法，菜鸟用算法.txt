```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        
        auto last1 = std::unique(nums1.begin(), nums1.end());
        nums1.erase(last1, nums1.end());
        
        auto last2 = std::unique(nums2.begin(), nums2.end());
        nums2.erase(last2, nums2.end());
        
        std::set_intersection(nums1.begin(), nums1.end(),
                             nums2.begin(), nums2.end(),
                             std::back_inserter(v));
        return v;
    }
};
```

先排序，后去重，然后上交集。用STL duang的一下就好了，可是面试官不让。