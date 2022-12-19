### 解题思路
笨办法，nums2插入到nums1中，同时nums1中被插入后面的数据整体向后移动。

### 代码

```c
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int k = n,i=0,j=0,l;
    while(k)
    {
        if(nums1[i]<=nums2[j]&&i<(m+j)) //i<(m+j)是为了让i小于nums1中的实时数据个数，防止i指向null
        {
            i++;
        }

        else
        {
            for(l=(m-1+j);l>=(i);l--)
            {
                nums1[l+1]=nums1[l];
            }
            nums1[i]=nums2[j];
            i++;
            j++;
            k--;
        }
    }

}
```