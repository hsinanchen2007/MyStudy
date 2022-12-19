### 解题思路
执行用时 :
36 ms, 在所有 C++ 提交中击败了35.16%的用户
内存消耗 :7.3 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m > n) return findMedianSortedArrays(nums2, nums1);
        int len = (m + n + 1) / 2;
        int iMin = 0, iMax = m;
        while(iMin < iMax){
            int m1 = iMin + (iMax - iMin) / 2;
            int m2 = len - m1;
            if(nums1[m1] < nums2[m2-1]){
                iMin = m1+1;
            }
            else{
                iMax = m1;
            }
        }
        double c1, c2;
        c1 = max(iMin>0?nums1[iMin-1]:-DBL_MAX, len-iMin>0?nums2[len-iMin-1]:-DBL_MAX);
        // return len-iMin;
        if((m+n) %2 == 1){
            return c1;
        }
        c2 = min(iMin<m?nums1[iMin]:DBL_MAX, len-iMin<n?nums2[len-iMin]:DBL_MAX);
        return (c1+c2) * 0.5;
    }
};
```