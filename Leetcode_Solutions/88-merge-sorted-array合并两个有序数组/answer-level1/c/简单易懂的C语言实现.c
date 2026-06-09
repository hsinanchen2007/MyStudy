    思路很简单，只需要将nums2中的数据全部插入nums1中，然后再对nums1中的数据进行排序即可。
### 代码

```c
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int i,j,temp;
    for(i=1;i<=n;i++)
        nums1[m+i-1]=nums2[i-1];
    for(i=0;i<m+n;i++)
    {
        for(j=i+1;j<m+n;j++)
        {
            if(nums1[i]>nums1[j])
            {
                temp = nums1[i];
                nums1[i] = nums1[j];
                nums1[j] = temp;
            }
        }
    }
}
```