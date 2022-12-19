### 解题思路
将数组1与数组2按照排序合并，再从最终的数组中取出中位数

### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int l1 = nums1 != null ? nums1.length : 0;
        int l2 = nums2 != null ? nums2.length : 0;
        int lm = l1 + l2;
        int[] merge = new int[lm];
        if (nums1 == null) {
            merge = nums2;
        } else if (nums2 == null) {
            merge = nums1;
        } else {
            int i1 = 0, i2 = 0, im = 0;
            while (i1 < l1 && i2 < l2 && im < lm) {
                if (nums1[i1] < nums2[i2]) {
                    merge[im++] = nums1[i1++];
                } else {
                    merge[im++] = nums2[i2++];
                }
            }
            if (l1 - i1 > 0) {
                System.arraycopy(nums1, i1, merge, im, l1 - i1);
            } else if (l2 - i2 > 0) {
                System.arraycopy(nums2, i2, merge, im, l2 - i2);
            }
        }
        return (merge[(lm - 1) / 2] + merge[lm / 2]) / 2.0;
    }
}
```