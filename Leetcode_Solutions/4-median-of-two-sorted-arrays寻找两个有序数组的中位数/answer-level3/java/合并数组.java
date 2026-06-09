### 解题思路
1.先将两个有序数组合并（时间复杂度为m+n，空间复杂度m+n），消耗额外空间数组保存合并后的数组
2.根据合并后的数组进行寻找中位数，对合并后数组取长度判断奇偶

### 代码

```java
class Solution {
       public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] nums = merge(nums1, nums2);
        return findMedian(nums);
    }

    private int[] merge(int[] nums1, int[] nums2) {
        if (nums1.length == 0) {
            return nums2;
        }
        if (nums2.length == 0) {
            return nums1;
        }
        int totalLenght = nums1.length + nums2.length;
        int[] nums = new int[totalLenght];
        if (nums1[nums1.length - 1] < nums2[0]) {
            System.arraycopy(nums1, 0, nums, 0, nums1.length);
            System.arraycopy(nums2, 0, nums, nums1.length, nums2.length);
            return nums;
        }
        if (nums1[0] > nums2[nums2.length - 1]) {
            System.arraycopy(nums2, 0, nums, 0, nums2.length);
            System.arraycopy(nums1, 0, nums, nums2.length, nums1.length);
            return nums;
        }
        int i = 0, j = 0, k = 0;
        while (i < nums1.length && j < nums2.length) {
            nums[k++] = nums1[i] >= nums2[j] ? nums2[j++] : nums1[i++];
        }
        for (int x = i < nums1.length ? i : j; x < (i < nums1.length ? nums1.length : nums2.length); x++) {
            nums[k++] = i < nums1.length ? nums1[x] : nums2[x];
        }
        return nums;
    }

    private double findMedian(int[] nums) {
        if (nums.length == 1) {
            return nums[0];
        }
        if ((nums.length & 0x1) == 0x1) {
            return (double) nums[nums.length / 2];
        }
        return (double) (nums[nums.length / 2] + nums[(nums.length / 2) - 1]) / 2;
    }
}
```