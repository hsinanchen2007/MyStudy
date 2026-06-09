```
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {        
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        std::set<int> temp;
        std::set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), std::inserter(temp, temp.begin()));
        std::vector<int> result;
        std::copy(temp.begin(), temp.end(), std::back_inserter(result));
        return result;
    }
};
```
