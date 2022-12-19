### 解题思路
双指针从后向前, 不需要额外的分配空间

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1;
        int p2 = n - 1;
        int p = m + n - 1;
        while (p1 > -1 && p2 > -1)
        {
            nums1[p--] = nums1[p1] > nums2[p2] ? nums1[p1--] : nums2[p2--];
        }

        for(int i = 0; i <= p2; i++){
            nums1[i] = nums2[i];
        }
    }
};
```