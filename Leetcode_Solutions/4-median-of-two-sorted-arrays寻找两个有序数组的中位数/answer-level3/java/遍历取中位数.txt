### 解题思路
可以不必将两个数组完全遍历完，遍历到中位数下标位置，将中位数取出。不用开辟新的数组，节省空间。

### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int len1 = nums1.length, len2 = nums2.length;
        int i = 0, j = 0, k = 0, midI = (len1 + len2) / 2;
        int mid = 0, pre = 0;

        while (i < len1 && j < len2 && k <= midI) {
            if (nums1[i] < nums2[j]) {
                if (k == midI) {
                    mid = nums1[i];
                }
                if (k == midI - 1) {
                    pre = nums1[i];
                }
                k ++;
                i ++;
            }
            if (i < len1 && nums2[j] <= nums1[i]) {
                if (k == midI) {
                    mid = nums2[j];
                }
                if (k == midI - 1) {
                    pre = nums2[j];
                }
                k ++;
                j ++;
            }
        }

        while (i < len1 && k <= midI) {
            if (k == midI) {
                    mid = nums1[i];
                }
                if (k == midI - 1) {
                    pre = nums1[i];
                }
                k ++;
                i ++;
        }
        while (j < len2 && k <= midI) {
            if (k == midI) {
                mid = nums2[j];
            }
            if (k == midI - 1) {
                pre = nums2[j];
            }
            k ++;
            j ++;
        }

        if ((len1 + len2) % 2 == 0) {
            return (mid + pre) / 2.;
        } else {
            return mid;
        }
    }
}
```