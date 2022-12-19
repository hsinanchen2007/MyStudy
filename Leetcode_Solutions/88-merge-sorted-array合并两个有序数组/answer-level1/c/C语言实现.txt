C语言实现
```C []
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i = m + n;
    while (m || n){
        nums1[--i] = (m && n) ? (nums1[m - 1] > nums2[n - 1] ? nums1[--m] : nums2[--n]) : (m ? nums1[--m] : nums2[--n]);
    }
}
```