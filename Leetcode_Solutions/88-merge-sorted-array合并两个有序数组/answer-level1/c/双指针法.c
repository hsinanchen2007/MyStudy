### 解题思路
利用两个指针i, j分别从两个数组的尾部开始往前遍历，将nums2数组插入到nums1中。当退出while循环的时候，nums1和nums2数组必然有一个已经被完全插入了。如果是nums2被插入完了，那就可以直接得出结果了。如果是nums1被插入完了，那还需要把nums2剩下当元素插入到nums1最前面（因为剩下的都是最小的数，所以可以直接将剩下的数插入到最前面）。

### 代码

```c
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int len = m + n - 1;
    int i = m - 1, j = n - 1;
    if (m == 0) {
        for (int k = 0; k < n; ++k) {
            nums1[k] = nums2[k];
        }
        return;
    }
    while (i >=0 && j >= 0) {
        nums1[len--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
    }

    if (j >= 0) {
        for (int k = 0; k <= j; ++k) {
            nums1[k] = nums2[k];
        }
    }
}
```