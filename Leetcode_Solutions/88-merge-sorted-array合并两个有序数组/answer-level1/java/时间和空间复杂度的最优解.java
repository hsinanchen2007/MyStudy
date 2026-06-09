### 解题思路
最简单的方法肯定是新建一个数组，然后两个数组依次往后遍历了，但这也太简单了，而且题目给的nums1的那么大空间就浪费了,nums1后面还有空余空间，那么我们可以从后往前遍历两个数组，往nums1的后面塞就行了.
时间复杂度O(m+n) 空间复杂度O(1)

### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int pos1 = m - 1;
        int pos2 = n - 1;
        //        for (int l = m + n - 1; l > 0; l--) {
        //            if (pos1 < 0 || pos2 < 0) {
        //                break;
        //            }
        //            if (nums1[pos1] > nums2[pos2]) {
        //                nums1[l] = nums1[pos1];
        //                pos1--;
        //            } else {
        //                nums1[l] = nums2[pos2];
        //                pos2--;
        //            }
        //        }
        //        if (pos2 >= 0) {
        //            for (int i = 0; i <= pos2; i++) {
        //                nums1[i] = nums2[i];
        //            }
        //        }
        //循环的条件可以优化下，因为l不会到0的，没必要这样循环，pos2小于0就可以结束了
        int l = m + n - 1;
        while (pos2 >= 0) {
            if (pos1 < 0) {
                nums1[l--] = nums2[pos2--];
            } else {
                if (nums1[pos1] >= nums2[pos2]) {
                    nums1[l--] = nums1[pos1--];
                } else {
                    nums1[l--] = nums2[pos2--];
                }
            }
        }

    }
}

```