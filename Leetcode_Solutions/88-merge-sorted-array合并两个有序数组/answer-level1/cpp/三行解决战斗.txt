```c++
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i1 = m - 1, i2 = n - 1, i3 = m + n - 1;
        while (i2 >= 0 && i1 >= 0)  nums1[i3--] = nums1[i1] > nums2[i2] ? nums1[i1--] : nums2[i2--];
        if (i1 < 0) for (int i = 0; i <= i2; ++i) nums1[i] = nums2[i];  
    }
};
```

 - 定义了三个指针i1, i2, i3分别放置在nums1最大元素位置，nums2最大元素位置，和nums1的最后位置。
 - 每次对nums1和nums2的指针位置进行决斗，胜者放在i3处。
 - 由于在向前遍历的过程中，所有的元素都被安置了，所以不需要额外的存储空间存放元素。
