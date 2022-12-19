### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public static double findMedianSortedArrays(int[] nums1, int[] nums2) {

        int length1 = nums1.length;
        int length2 = nums2.length;

        int k1 = (length1 + length2 + 1) / 2;


        double kdata_1 = getKdata(nums1, 0, length1 - 1, nums2, 0, length2 - 1, k1);

        int k2 = (length1 + length2) % 2 != 0 ? -1 : k1 + 1;

        double kdata_2 = 0;
        if (k2 > 0) {
            kdata_2 = getKdata(nums1, 0, length1 - 1, nums2, 0, length2 - 1, k2);
            return (kdata_1+kdata_2)*0.5;
        }else{
            return kdata_1;
        }
    }

    private static double getKdata(int[] nums1, int start1, int end1, int[] nums2, int start2, int end2, int k) {

        int leng1 = end1 - start1 + 1;
        int leng2 = end2 - start2 + 1;

        if (leng1 > leng2) {

            return getKdata(nums2, start2, end2, nums1, start1, end1, k);
        }

        if (leng1 == 0) {
            return nums2[start2 + k - 1];
        }

        if (k == 1) {
            return Math.min(nums1[start1], nums2[start2]);
        }


        int i = start1 + Math.min(leng1, k / 2) - 1;
        int j = start2 + Math.min(leng2, k / 2) - 1;

        if (nums1[i] > nums2[j]) {

            return getKdata(nums1, start1, end1, nums2, j + 1, end2, k - (j - start2 + 1));
        } else {
            return getKdata(nums1, i + 1, end1, nums2, start2, end2, k - (i - start1 + 1));
        }
    }
}
```