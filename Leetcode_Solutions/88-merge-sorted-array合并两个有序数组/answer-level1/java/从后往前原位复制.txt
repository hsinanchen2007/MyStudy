### 解题思路

直接原位复制，从后往前复制数组元素，直到两个列表都复制完成，需要考虑两个数组的其中一个甚至两个数组都是空数组的情况。

### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        while (m > 0 || n > 0) {
            if (m > 0 && n > 0 && nums1[m - 1] > nums2[n - 1]) {
                nums1[m + n - 1] = nums1[m - 1];
                m -= 1;
            } else if (n > 0) {
                nums1[m + n - 1] = nums2[n - 1];
                n -= 1;
            } else {
                break;
            }
        }
    }
}
```