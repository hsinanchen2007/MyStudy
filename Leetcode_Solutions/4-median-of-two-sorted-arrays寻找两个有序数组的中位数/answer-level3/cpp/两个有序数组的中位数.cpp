### 解题思路
中位数作用：将一个集合划分为两个长度相等的子集，其中一个子集中的数小于中位数，另一个子集大于；
考虑临界条件：i=0 和 j=0的情况 

### 代码

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 中位数作用：将一个集合划分为两个长度相等的子集，其中一个子集中的数小于中位数，另一个子集大于；
        //  nums1: 0~n, 0<=i<=n; nums2: 0~m, 0<=j<=m;
        // n<m; j = (n+m+1)/2-i; nums1[i-1]<nums2[j+1]&&nums1[i+1] > nums2[j-1]
        // 临界条件： i=0 || j==0 时 i-1 和 j-1不存在;
        // 如果  1.nums1[i-1] > nums2[j+1];  i--;
        //       2.nums2[j-1] > nums1[i+1];  i++;
         
        if(nums1.size()>nums2.size())
        // 保证nums1的size较小
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();
        int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;

        while (iMin <= iMax) {
            int i = (iMin + iMax) / 2;
            int j = halfLen - i;

            if (i < iMax && nums2[j-1] > nums1[i]){
                iMin = i + 1; // i is too small
            }else if (i > iMin && nums1[i-1] > nums2[j]) {
                iMax = i - 1; // i is too big
            } else { // i is perfect
                int maxLeft = 0;
                if (i == 0 ) { maxLeft = nums2[j-1]; }
                else if (j == 0) { maxLeft = nums1[i-1]; }
                else { maxLeft = nums1[i-1]>nums2[j-1]?nums1[i-1]:nums2[j-1]; }   // 大值
                if ( (m + n) % 2 == 1 ) { return maxLeft; }

                int minRight = 0;
                if (i == m) { minRight = nums2[j]; }
                else if (j == n) { minRight = nums1[i]; }
                else { minRight = nums1[i]<nums2[j]?nums1[i]:nums2[j]; }   // 小值

                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0;
    }
};
```