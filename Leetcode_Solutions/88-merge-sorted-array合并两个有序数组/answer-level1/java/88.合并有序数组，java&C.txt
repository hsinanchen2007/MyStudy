
```java []
    /**
     * 关键点是从后往前放
     * 执行用时 :0 ms, 100.00%
     * 内存消耗 :36 MB, 85.64%
     */
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        if (nums1 == null || nums1.length == 0 || nums2 == null || nums2.length == 0)
            return;
        int i = m - 1, j = n - 1;
        int k = nums1.length - 1;
        while (i >= 0 && j >= 0)
            nums1[k--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];

        while (j >= 0)
            nums1[k--] = nums2[j--];
    }
```

```c []
/**
 * C炫技写法,一行搞定^_^~
 * 执行用时 :4 ms, 94.92%
 * 内存消耗 :7.3 MB, 71.61%
 */
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    while(n>0) nums1[--nums1Size] = n>0 && m>0 && nums1[m-1] > nums2[n-1] ? nums1[--m] : nums2[--n];
}
```

