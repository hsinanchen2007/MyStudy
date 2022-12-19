### 解题思路
从右侧大的数据开始遍历比较，只要某个数组元素用完，跳出遍历；
若是nums1还有剩余，不用管；
若是nums2有剩余，则全部对应赋值到nums1中，完成排序；
时间复杂度O(n)，空间复杂度O(1)。

### 代码

```c
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){

    int i = m-1, j = n-1;

    for(int k = m+n-1; ((k >= 0)&&(i>=0)&&(j>=0)); k--)
    {
        if(nums1[i]>nums2[j])
        {
            nums1[k] = nums1[i];
            i--;
        }
        else
        {
            nums1[k] = nums2[j];
            j--;
        }
    }
    if(j >= 0)   //如果nums2排序有剩余
    {
         for(; j>= 0;j--)
        {
            nums1[j] = nums2[j];
        }
    }
}
```