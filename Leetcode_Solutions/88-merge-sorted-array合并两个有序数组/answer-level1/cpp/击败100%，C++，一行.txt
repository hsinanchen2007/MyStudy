根据官方题解的思路，从尾向前进行merge。利用STL<algoritm>提供的merge，传入反向迭代器即可。
```
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        std::merge(nums1.rbegin() + nums1.size() - m, nums1.rend(), nums2.rbegin(), nums2.rend(), nums1.rbegin(), greater<int>{});
    }
};
```