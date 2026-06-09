
双指针，从尾部开始
```
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i, a=m-1, b=n-1;
    for(i=m+n-1;i>=0;i--){
        if(a<0) {nums1[i]=nums2[b--]; continue;}
        if(b<0) {nums1[i]=nums1[a--]; continue;} 
        if(nums1[a]>nums2[b]) nums1[i]=nums1[a--];
        else nums1[i]=nums2[b--];
    }
}
```
