利用指针, 从num1最后一位开始向前遍历
**note:** 如果m=0(num1全为0值),直接将num2复制给num1
```
class Solution {
    public static void merge(int[] nums1, int m, int[] nums2, int n) {

        int pos = m + n - 1;
        while (pos >= 0) {
            if (m == 0) {
                System.arraycopy(nums2, 0, nums1, 0, n);
                break;
            }

            if (n == 0 || nums1[m - 1] > nums2[n - 1]) {
                nums1[pos] = nums1[m - 1];
                m--;
            } else {
                nums1[pos] = nums2[n - 1];
                n--;
            }
            pos--;
        }
    }
}
```
