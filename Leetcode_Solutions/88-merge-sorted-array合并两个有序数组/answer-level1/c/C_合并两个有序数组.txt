### 解题思路

### 代码

```c
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int* temp=(int*)malloc(sizeof(int)*(m+n));
    int i=0,j=0,iter=0;
    while(i!=m&&j!=n)
    {
        if(nums1[i]<nums2[j])
            temp[iter++]=nums1[i++];
        else
            temp[iter++]=nums2[j++];
    }
    while(i<m)
        temp[iter++]=nums1[i++];
    while(j<n)
        temp[iter++]=nums2[j++];
    
    for(int i=0;i<(m+n);++i)
        nums1[i]=temp[i];
    free(temp);
}
```