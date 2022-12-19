既然本来就是两个有序的数组，那么只需要从尾部比较，找到大的那一个放在结尾。比较结束如果nums2里面还有值，就全部放在nums1里面即可
```
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    while(m&&n)nums1[m+n]=nums1[m-1]>nums2[n-1]?nums1[--m]:nums2[--n];
    while(n)nums1[n]=nums2[--n];
}
```
