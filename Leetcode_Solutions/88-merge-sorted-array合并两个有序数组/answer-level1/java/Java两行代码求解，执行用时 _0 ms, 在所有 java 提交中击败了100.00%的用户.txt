

```Java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        while (m != 0 && n != 0) nums1[m + n - 1] = nums1[m - 1] > nums2[n - 1] ? nums1[--m] : nums2[--n]; 
        while (n != 0) nums1[m + n - 1] = nums2[--n];
    }
}
```

代码解析：
因为是有序的，且第一个数组有足够的空间，那么直接利用现有的m、n进行倒序判断大小
    第一个while 就是把最大的按照顺序从后放入，直到有一个下标位0
    第二个while 就是看m n 是否有没处理完成的，但是m如果没处理完就不用处理，因为本身就在nums1中，所以只需要看n是否不为0，不为0 则全部放入到nums1中