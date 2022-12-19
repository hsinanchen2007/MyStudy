### 解题思路
两指针的目的就是为了不走重复的步骤

### 代码
从后向前遍历，不需要创建额外空间
```
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int j=m+n-1,p=m-1,q=n-1;
    while(p>=0||q>=0)
    {
        if(p>=0&&q>=0)
        {
            if(nums1[p]>nums2[q])
                nums1[j--]=nums1[p--];
            else
                nums1[j--]=nums2[q--];
        }
        if(p<0 &&q>=0)
        {
            while(q>=0)
                nums1[j--]=nums2[q--];
        }
        if(p>=0&&q<0)
        {
            while(p>=0)
                nums1[j--]=nums1[p--];
        }
    }
}
```
由前向后遍历，需要额外创建空间
```
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int m1=m;
    int j=0,p=0,q=0;
    int *a=(int*)malloc(m*sizeof(int));
    for(int i=0;i<m;i++)
    {
        a[i]=nums1[i];
    }
    while(p<m||q<n)
    {
        if(p<m&&q<n)
        {
            if(a[p]<nums2[q])
            {
                nums1[j++]=a[p++];
            }
            else
            {
                nums1[j++]=nums2[q++];
            }
        }
        if(p>=m&&q<n)
        {
            while(q<n)
            {
                nums1[j++]=nums2[q++];
            }
        }
        if(p<m&&q>=n)
        {
            while(p<m)
            {
                nums1[j++]=a[p++];
            }
        }
    }
}
```
此处两个其实差别不大

