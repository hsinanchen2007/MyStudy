```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int[] newNums = Arrays.copyOf(nums1, m);
        int left1 = 0;
        int left2 = 0;
        int newT = 0;
        while (left1 < m && left2 < n) {
            if (newNums[left1] >= nums2[left2]) {
                nums1[newT++] = nums2[left2++];
            } else {
                nums1[newT++] = newNums[left1++];
            }
        }
        while (left1 < m) {
            nums1[newT++] = newNums[left1++];
        }

        while (left2 < n) {
            nums1[newT++] = nums2[left2++];
        }
    }
}
```
