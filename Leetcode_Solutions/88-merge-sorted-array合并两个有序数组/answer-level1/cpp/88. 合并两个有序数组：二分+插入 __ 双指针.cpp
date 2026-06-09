### 解题思路
* 使用lower_bound()（<algorithm>）查出插入位置
* 双指针

### 代码
* 二分+插入
* 最坏O(n*m)；空O(1);
```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0; i<n; i++) {
            auto pos = lower_bound(nums1.begin(), nums1.begin() + m, nums2[i]);
            if(pos == nums1.begin()+m)
                nums1[m] = nums2[i];
            else {
                nums1.insert(pos, nums2[i]);
            }
            m++;
        }
        nums1.resize(m);    // 如果有插入中间，则可能出现nums1的size变大，所以最后resize到m
    }
};
```
![5.png](https://pic.leetcode-cn.com/037ef53156207d1e8e215a7c978da1bcf6eccabced903869e4ad72e7406e756a-5.png)

* 双指针从前往后
* O(m+n), O(m)
```cpp
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(nums2.empty())   return ;

        vector<int> nums1_c(nums1.begin(), nums1.begin() + m);
        int p1 = 0, p2 = 0;
        int i = 0;
        while(p1 < m && p2 < n) {
            if(nums1_c[p1] > nums2[p2]) {
                nums1[i++] = nums2[p2++];
            }
            else    nums1[i++] = nums1_c[p1++];
        }
        while(p1 < m) {
            nums1[i++] = nums1_c[p1++];
        }
        while(p2 < n) {
            nums1[i++] = nums2[p2++];
        }
    }
```
![1.png](https://pic.leetcode-cn.com/823424998e1dc5048669ddc61725e767d2f9157b66bf5f8f81cdf0bf87a8e2d3-1.png)

* 双指针从后往前
* O(m+n), O(1)
```cpp
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(nums2.empty())   return ;

        int i = m + n - 1;      // i-- 在到达-1时结束访问
        int p1 = m - 1;
        int p2 = n - 1;
        while(p1 >= 0 && p2 >= 0) {
            if(nums1[p1] > nums2[p2]) {
                nums1[i--] = nums1[p1--];
            }
            else {
                nums1[i--] = nums2[p2--];
            }
        }
        while(p1 >= 0) {
            nums1[i--] = nums1[p1--];
        }
        while(p2 >= 0) {
            nums1[i--] = nums2[p2--];
        }

    }
```
![2.png](https://pic.leetcode-cn.com/3cb6075dd083f23ad340ada7d6b5bc43822ef05db44183f23242b17ea541b6f0-2.png)
