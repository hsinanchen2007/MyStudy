### 解题思路

std::set_intersection

注意要用有序集合，因为：`Constructs a sorted range beginning at d_first consisting of elements that are found in both sorted ranges [first1, last1) and [first2, last2). If some element is found m times in [first1, last1) and n times in [first2, last2), the first std::min(m, n) elements will be copied from the first range to the destination range. The order of equivalent elements is preserved. The resulting range cannot overlap with either of the input ranges. `

### 代码

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> d1;
        set<int> d2;
        vector<int> res;
        for(int n: nums1)
            d1.insert(n);
        for(int m: nums2)
            d2.insert(m);
        std::set_intersection(d1.begin(), d1.end(), d2.begin(), d2.end(), std::back_inserter(res));
        return res;
    }
};
```