执行用时：4ms
内存消耗：5.7MB
```
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int r = m+n-1;
    int i=m-1, j=n-1;
    while(i>=0&&j>=0){
        if(nums1[i]>nums2[j]) nums1[r--]=nums1[i--];
        else nums1[r--]=nums2[j--];
    }
    while(j>=0) nums1[r--]=nums2[j--];
}
```
