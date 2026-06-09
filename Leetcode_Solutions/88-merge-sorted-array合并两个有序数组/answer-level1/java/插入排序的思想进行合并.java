### 解题思路
使用插入排序的思想进行处理
### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
     int index = 0;
        if (0 == m) {
            for (int i = 0; i < n;i++)
                nums1[i]  = nums2[i];
            return;
        }
        if (0 == n)
            return;

        for (int i = 0; i < n; i++) {
            index = m + i - 1;
            while (index >= 0 && nums2[i] < nums1[index] ) {
                nums1[index + 1] = nums1[index];
                index--;
            }
            nums1[index + 1] = nums2[i];
        }
    }
}
```