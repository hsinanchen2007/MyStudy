### 解题思路
此处撰写解题思路
使用双向指针利用数组索引 从后往前以此覆盖数组一
### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        //创建两个索引指针 从后往前一次比较对数组一进行覆盖
        int p1 = m - 1;
        int p2 = n - 1;
        int merge = m + n - 1;
        while (p1 >=0 || p2 >= 0) {
            if (p1 < 0) {
                nums1[merge--] = nums2[p2--];
            } else if (p2 < 0) {
                nums1[merge--] = nums1[p1--];
            } else if (nums1[p1] > nums2[p2]) {
                nums1[merge--] = nums1[p1--];
            } else {
                nums1[merge--] = nums2[p2--];
            }
        }
    }
}
```