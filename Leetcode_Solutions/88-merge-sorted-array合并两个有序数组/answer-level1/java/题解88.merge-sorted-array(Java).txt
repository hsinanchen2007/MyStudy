### 解题思路
经典的双指针解决，和前边一道合并有序链表一样，从后开始用指针，可以有效解决空间问题，因为nums1的最后m个位置都是可以利用起来的。

### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        //设置两个指针分别指向两个数组的非零部分的尾端，向前遍历
        int p1 = m - 1;
        int p2 = n - 1;
        //设置指针指向存储结果的数组num1的尾端，即从后向前存储
        int p = m + n - 1;

        while ((p1 >= 0) && (p2 >= 0)) {
            if (nums1[p1] < nums2[p2]) nums1[p--] = nums2[p2--];
            else nums1[p--] = nums1[p1--];
        }
        if (p2 >= 0) {
            for (int loop = p2; p2 >= 0; p2--) {
                nums1[p--] = nums2[p2];
            }
        }
    }
}
```