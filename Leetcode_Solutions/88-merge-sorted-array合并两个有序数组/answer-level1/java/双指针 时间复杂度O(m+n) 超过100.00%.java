### 解题思路
看代码

### 代码

```java
class Solution {
 //从起始位置设置两个指针，一个指向数组1，一个指向数组2
    //空间换时间
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int[] current = new int[m + n];
        int i = 0;
        int j = 0;
        int count = 0;
        while (i < m || j < n) {
            //如果两个数都没有遍历完，继续比较
            if (i < m && j < n) {
                if (nums1[i] < nums2[j]) {
                    current[count++] = nums1[i];
                    i++;
                } else if (nums1[i] > nums2[j]) {
                    current[count++] = nums2[j];
                    j++;
                } else {
                    current[count++] = nums1[i];
                    current[count++] = nums2[j];
                    i++;
                    j++;
                }
                //如果两个数组中其中一个遍历完了，就把剩下的直接赋值给目标数组
            } else {
                System.arraycopy(nums2, j, current, count, n - j);
                System.arraycopy(nums1, i, current, count, m - i);
                break;
            }
        }
        System.arraycopy(current, 0, nums1, 0, current.length);
}
```