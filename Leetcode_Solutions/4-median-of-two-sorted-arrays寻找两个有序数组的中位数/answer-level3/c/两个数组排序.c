### 解题思路
建立一个新的长度为两个数组中位数长度的数组记录排序，遍历两个数组比较大小，总是将小的数存在新数组中，等到得到中位数就计算中位数并返回

### 代码

```c
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    if(nums1Size+nums2Size==1)
    {
        if(nums1Size==0)
        return nums2[0];
        else
        return nums1[0];
    }


    int flag = 1;
    if((nums1Size+nums2Size)%2==0)
    flag = 2;
    int length;
    length = (nums1Size+nums2Size)/2+1;
    int num3[length];
    int i,j,k;
    i=0;
    j=0;
    k=0;
    while(i<nums1Size && j<nums2Size)
    {
        if(nums1[i]<nums2[j])
        {
            num3[k]=nums1[i];
            k++;
            i++;
        }
        else
        {
            num3[k]=nums2[j];
            k++;
            j++;
        }
        if(k==length)
        break;
    }
    if(i<nums1Size)
    {
        while(k<length)
        {
            num3[k]=nums1[i];
            k++;
            i++;
        }
        
    }
    if(j<nums2Size)
    {
        while(k<length)
        {
            num3[k]=nums2[j];
            k++;
            j++;
        }
    }
    double minNum;
    if(flag == 1)
    {
        minNum = (double)num3[length-1];
        
    }
    else if(flag == 2)
    {
        minNum = ((double)num3[length-1]+(double)num3[length-2])/2.0;
    }
    return minNum;
}
```