### 解题思路
此处撰写解题思路

### 代码

```c
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int i;
    int j;
    int l=nums1Size+nums2Size;
    double p[nums1Size+nums2Size];
    for(i=0;i<nums1Size;i++)
    {
        p[i]=nums1[i];
    }
    for(j=0;j<nums2Size;j++)
    {
        p[nums1Size]=nums2[j];
        nums1Size++;
    }
    int t,m,n;
    for(m=0;m<l-1;m++)
    {
        for(n=0;n<l-m-1;n++)
        {
            if(p[n]>p[n+1])
            {
                t=p[n];
                p[n]=p[n+1];
                p[n+1]=t;
            }
        }
    }
    double r;
    if(l%2==0)
    {
        r=(p[l/2-1]+p[l/2])/2;
    }
    else
    {
        r=p[(l-1)/2];
    }
    return r;
}
```
