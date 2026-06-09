### 解题思路
另开数组合并，空间复杂度O(n+m),时间复杂度O(n+m)

### 代码

```c
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int total=m+n;
    int* res=(int*)malloc(sizeof(int)*(total));
    int i=0;int j=0;int k=0;
    while(i<m&&j<n)
    {
        if(nums1[i]<=nums2[j])
        {
            res[k++]=nums1[i];
            i++;
        } 
        if(nums1[i]>nums2[j])
        {
            res[k++]=nums2[j];
            j++;
        }
    }
    if(i==m) while(j<n) res[k++]=nums2[j++];
    if(j==n) while(i<m) res[k++]=nums1[i++];
    
    for(int i=0;i<total;i++)
    {
        nums1[i]=res[i];
    }
    
    
}
```