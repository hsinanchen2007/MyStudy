### 解题思路
还是插入排序的思想,但是采用了leetcode官方提供的代码思想, 复制一个nums1, 通过把空间复杂度提升到 O(m), 降低时间复杂度为 O(m+n)
![Screenshot from 2019-01-08 15-02-28.png](https://pic.leetcode-cn.com/f00be5927fadc6138139a764178c785bfeb32845b35513a42b1c3ef3a462daf0-Screenshot%20from%202019-01-08%2015-02-28.png)
### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
      int[] temp = new int[m];
        System.arraycopy(nums1, 0, temp, 0, m);
        int i = 0, j = 0;
        int index = 0;
        while (i < m && j < n)
            nums1[index++] = (temp[i] < nums2[j]) ? temp[i++] : nums2[j++];
        if (i < m)
            System.arraycopy(temp, i, nums1, index, m - i);
        if (j < n)
            System.arraycopy(nums2, j, nums1, index, n - j);
    }
}
```