### 解题思路

由大往小（由前往后）遍历存放

### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int k1 = m - 1;
        int k2 = n - 1;
        while (k1 >= 0 && k2 >= 0) {
            if (nums1[k1] > nums2[k2]) {
                nums1[k1 + k2 + 1] = nums1[k1];
                k1--;
            } else {
                nums1[k1 + k2 + 1] = nums2[k2];
                k2--;
            }
        }
        while (k2 >= 0) {
            nums1[k1 + k2 + 1] = nums2[k2];
            k2--;
        }
    }
}
```