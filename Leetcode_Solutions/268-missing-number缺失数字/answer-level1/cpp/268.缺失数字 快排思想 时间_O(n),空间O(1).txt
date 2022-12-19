快排是一个很妙的算法,由快排思想可以引申出`O(n)`求第K大数的算法

可惜鄙人对这种思想的理解甚是肤浅,只知道时间复杂度,却不知如何推导 *(详情可网上搜索)*

---

本题可基于这种想法构造出算法

每次选定中值,把比它小的放左边,比它大的放右边

如果中间位置是中值,则 [0,中值] 没有缺失的,缺失的在右边

如果中间的位置比中值小,则 [0,中值] 有缺失

因为比较懒,直接用了库函数`nth_element`*(也请网上搜索,抱歉)*

---

```c++
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l = 0, r = nums.size(), i = 0, j = nums.size();
        while(l < r)
        {
            int mid = (l+r)/2;
            nth_element(nums.begin()+i, nums.begin()+mid, nums.begin()+j);
            if(nums[mid] == mid)
            {
                l = mid+1;
                i = mid+1;
            }
            else if(nums[mid] > mid)
            {
                r = mid;
                j = mid+1;
            }
        }
        return l;
    }
};
```
---

那么实际体验如何呢?

36 ms 糟心了~