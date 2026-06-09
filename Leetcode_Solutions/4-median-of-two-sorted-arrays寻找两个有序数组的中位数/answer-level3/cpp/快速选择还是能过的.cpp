### 解题思路
合并数组，用快速选择，时间复杂度为O(n+m),还是能过

### 代码

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        double m1,m2;for(auto x:nums1)printf("%d ",x);
        nth_element(nums1.begin(),nums1.begin()+(m+n-1)/2,nums1.end());
        m1=nums1[(m+n-1)/2];
        nth_element(nums1.begin(),nums1.begin()+(m+n)/2,nums1.end());
        m2=nums1[(m+n)/2];
        return (m1+m2)/2.0;
    }
};
```