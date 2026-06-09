### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        if ((nums1 == null || nums1.length == 0) && (nums2 == null || nums2.length == 0)) {
            return 0;
        }
        int len1 = 0;
        int len2 = 0;
        if (nums1 == null || nums1.length == 0) {
            return getMedianNum(nums2);

        }
        if (nums2 == null || nums2.length == 0) {
            return getMedianNum(nums1);
        }
        len2 = nums2.length;
        len1 = nums1.length;
        int item = 0;
        int length = len1 + len2;
        int index = 0;
        for (int i = 0, j = 0; index < length; index++) {
            if (i == len1) {
                item = nums2[j];
                j++;
            } else if (j == len2) {
                item = nums1[i];
                i++;
            } else if (nums1[i] > nums2[j]) {
                item = nums2[j];
                j++;
            } else if (nums1[i] <= nums2[j]) {
                item = nums1[i];
                i++;
            }
            if (index >= (length - 1) / 2) {
                return length % 2 == 0 ? (doubleDiv((item + getMinNum(i, j, nums1, nums2)), 2)) : item;
            }
        }
        return -1;
    }

    private int getMinNum(int i, int j, int[] numi, int[] numj) {
        if (i >= numi.length) {
            return numj[j];
        }
        if (j >= numj.length) {
            return numi[i];
        }
        return Math.min(numi[i], numj[j]);
    }

    private double getMedianNum(int[] nums) {
        int length = nums.length;
        int index = length / 2;
        if (length % 2 == 0) {
            return doubleDiv((nums[index - 1] + nums[index]), 2);
        } else {
            return nums[index];
        }
    }
    private double doubleDiv(double v1, double v2) {
        return v1/v2;
    }
}
```