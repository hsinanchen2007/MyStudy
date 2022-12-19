### 解题思路
刚学了快排没多久，这道题用快排感觉很好

### 代码

```c
int compare(const void*a,const void*b)
{
    return(*(int*)a-*(int*)b);
}
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int i,j;
    for(i=m,j=0;i<nums1Size&&j<n;i++,j++)
    {
        nums1[i]=nums2[j];
    }
    qsort(nums1,n+m,sizeof(int),compare);
}
```