### 解题思路
    本题思路其实很简单，合并俩个排序数组即可，可以新建一个数组，将俩个数组中的数依次按大小顺序插入即可。代码如下所示。

### 代码

```c
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int pos = (nums1Size + nums2Size) / 2;  
    double record[100000];
    int i = 0, j = 0, t = 0;
    double now = 0.0;
    double ans = 0.0;
    while( i < nums1Size && j < nums2Size && t <= pos)
    {
        now = nums1[i] <= nums2[j] ? nums1[i++] : nums2[j++];
        record[t++] = now;
    }
    if( t<= pos)
    {
        while(i < nums1Size) record[t++] = nums1[i++];
        while(j < nums2Size) record[t++] = nums2[j++];
    }
    if((nums1Size + nums2Size) % 2 == 0)
        ans = (record[pos-1] + record[pos]) / 2;
    else
    {
        ans =record[pos];
    }
    return ans;
}
```