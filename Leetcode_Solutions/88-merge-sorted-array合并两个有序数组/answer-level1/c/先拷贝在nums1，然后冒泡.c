### 解题思路
先将nums2的元素拷贝到nums1后面，这样就变成我们熟知的排序。由于数组内元素部分是有序的，推荐使用冒泡排序，运行时间会少一点。

### 代码

```c
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    for(int i=0,j=m;i<n;i++,j++){
        nums1[j]=nums2[i];
    }
    for(int i=0;i<m+n;i++){
        for(int j=m+n-1;j>i;j--){
            if(nums1[j]<nums1[j-1]){
                int temp=nums1[j];
                nums1[j]=nums1[j-1];
                nums1[j-1]=temp;
            }
        }
    }
}
```