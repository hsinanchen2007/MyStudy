### 解题思路
因为两个数组都是有序的。遍历数组2的每个元素。插入到数组1中。

### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {

        for (int i = 0; i < n; i++) {
            insertItem(nums2[i], nums1, m);
            m++;
        }
    }

    private void insertItem(int numInsert, int[] nums1, int m) {
        if (!insert(numInsert, nums1, m)) {
            nums1[m] = numInsert;
        }
    }

    private boolean insert(int numInsert, int[] nums1, int m) {
        for (int i = 0; i < m; i++) {
            if (numInsert < nums1[i]) {
                moveOther(nums1, i, m);
                nums1[i] = numInsert;
                return true;
            }
        }
        return false;
    }

    private void moveOther(int[] nums1, int start, int m) {
        for (int i = m - 1; i >= start; i--) {
            nums1[i + 1] = nums1[i];
        }
    }
}
```