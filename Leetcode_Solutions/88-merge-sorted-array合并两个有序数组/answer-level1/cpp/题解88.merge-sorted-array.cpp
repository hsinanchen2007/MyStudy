### 解题思路
C++思路与java一致，但是另外还可借助vector的特性和函数实现：两数组先合并后排序。

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //设置两个指针分别指向两个数组的非零部分的尾端，向前遍历
        int p1 = m - 1;
        int p2 = n - 1;
        
        //设置指针指向存储结果的数组num1的尾端，即从后向前存储
        int p = m + n - 1;

        while (p1 >= 0 && p2 >= 0) 
            nums1[p--] = nums1[p1] < nums2[p2] ? nums2[p2--] : nums1[p1--];
        //如果nums2还有剩余，复制进nums1剩余位置
        while (p2 >= 0) nums1[p--] = nums2[p2--];
    }
};
```