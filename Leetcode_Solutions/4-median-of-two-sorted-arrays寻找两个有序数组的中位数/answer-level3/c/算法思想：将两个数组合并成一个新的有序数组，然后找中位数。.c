### 解题思路
此处撰写解题思路

### 代码

```c
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int num[nums1Size + nums2Size];
int i = 0, j = 0, k = 0;
int sum;
double a;
while(i < nums1Size && j < nums2Size){
    if(nums1[i] < nums2[j])
    {
        num[k] = nums1[i];
        k++;
        i++;
    }
    else
    {
        num[k] = nums2[j];
        k++;
        j++;
    }
}
    while(i < nums1Size)
    {
        num[k] = nums1[i];
        k++;
        i++;
    }
    while(j < nums2Size)
    {
        num[k] = nums2[j];
        k++;
        j++;
    }
sum = (nums1Size + nums2Size) ;
if((sum % 2) == 0)
{
    a = (num[sum / 2] + num[(sum / 2) - 1]) / 2.0;
    return(a);
}
else
{
    return (num[sum / 2]);
}
}

```