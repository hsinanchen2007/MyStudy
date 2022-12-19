### 解题思路


### 代码

```c
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
  for(int i=0;i<n;i++)
  *(nums1+m+i)=*(nums2+i);
  
  int min,j,temp;
  for(int i=0;i<m+n-1;i++)
  {
      min=i;
      for(j=i+1;j<m+n;j++)
        if(*(nums1+j)<*(nums1+min))
        min=j;
        temp=*(nums1+min);
        *(nums1+min)=*(nums1+i);
        *(nums1+i)=temp;
  }

}
```