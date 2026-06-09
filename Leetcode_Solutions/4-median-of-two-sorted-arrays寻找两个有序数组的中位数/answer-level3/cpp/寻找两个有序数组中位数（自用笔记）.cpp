### 解题思路
核心：二分查找

n：短的数组长度
m：长的数组长度

- m+n为奇数时，`左边的长度` = `右边的长度 + 1`，左边的长度为$\frac{m+m+1}{2}$，中位数是左边两个数组中最大的
- m+n为偶数时：`左边的长度` = `右边的长度`，左边的长度为$\frac{m+m}{2}$，因为C++中对整数除法是向下取整，所以$\frac{m+m+1}{2}$和$\frac{m+m}{2}$此时是一样的，所以和奇数的情况统一了，中位数是左边两个数组中最大的和右边两个数组中最小的平均数

c1、c2：分别表示两个数组中点靠右的位置（即单看一个数组时，右边那一半不超过左边那一半的长度，奇数时$L_左$=$L_右+1$，偶数时$L_左$=$L_右$）（目的是为了表示下面这个等式的数量关系更简洁）

为保证左边长度和的条件，有等式：$c1+c2=\frac{m+n+1}{2}$成立
$c1+c2$表示划分后的两个数组左半边的长度和

还有一个问题，如果划分到最后，短的数组已经到端点了，那么可能会访问越界，因此代码中使用了一个小Trick，越界就设为无穷大。并且两个数组都有可能达到端点，因此两个数组都要用到这个Trick

### 复杂度
时间：$O(log(m,n))$
空间：$O(1)$

### 代码

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size();
        int m = nums2.size();
        if(n > m){
            return findMedianSortedArrays(nums2, nums1);
        }

        int Lmax1, Lmax2, Rmin1, Rmin2, c1, c2;
        int lo = 0, hi = n;

        while(lo <= hi){
            c1 = (lo + hi + 1) / 2;
            c2 = (m + n + 1) / 2 - c1;

            Lmax1 = (c1 == 0) ? INT_MIN : (nums1[c1 -1]);
            Rmin1 = (c1 == n) ? INT_MAX : (nums1[c1]);
            Lmax2 = (c2 == 0) ? INT_MIN : (nums2[c2 - 1]);
            Rmin2 = (c2 == m) ? INT_MAX : (nums2[c2]);

            if(Lmax1 > Rmin2){
                hi = c1 - 1;
            }else if(Lmax2 > Rmin1){
                lo = c1 + 1;
            }else{
                break;
            }
        }
        
        if((m+n) % 2 == 0){
            return (max(Lmax1, Lmax2) + min(Rmin1, Rmin2)) / 2.0;
        }else{
            return max(Lmax1, Lmax2);
        }
    }
};
```