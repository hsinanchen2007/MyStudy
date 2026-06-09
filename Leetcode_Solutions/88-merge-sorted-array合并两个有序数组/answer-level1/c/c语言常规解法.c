### 解题思路
选择排序

### 代码

```c
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int j=0;
    for(int i=m;i<nums1Size;i++)
    {
            nums1[i]=nums2[j];
            j++;
    }
    for(int i=0;i<nums1Size;i++)
    {
        int min=i;
        for(int j=i;j<nums1Size;j++)
        {
            if(nums1[j]<nums1[min])
            {
                int temp=nums1[j];
                nums1[j]=nums1[min];
                nums1[min]=temp;
            }
        }
    }
}
```