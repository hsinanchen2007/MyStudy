### 解题思路
我就是把第二个数组合并到第一个数组里面去，然后用打擂台的方式进行排序，先暂时任命nums1[0]作为擂主，能者替换，结果是的，哈哈

### 代码

```c
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
int i,j,c;
for(i=0;i<n;i++)
    nums1[m+i]=nums2[i];
int count=m+n;
for(i=0;i<count-1;i++)
    {
        for(j=i+1;j<count;j++)
        {
            if(nums1[i]>nums1[j])
            {
                c=nums1[i];nums1[i]=nums1[j];nums1[j]=c;
            }
        }
    }
}
```