### 解题思路
从后往前遍历。i指向第一个数组的左后一个元素，j指向第二个数组的最后一个元素。p指向数组1的末尾。

### 代码

```c
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i=m-1;
    int j=n-1;
    int p=m+n-1;
    while(i>=0||j>=0)
    {
        if(i<0)
        {
            nums1[p]=nums2[j];
            p--;
            j--;
        }
        else if(j<0)
        {
            nums1[p]=nums1[i];
            p--;
            i--;
        }
        else if(nums1[i]>=nums2[j])
        {
            nums1[p]=nums1[i];
            p--;
            i--;
        }
        else
        {
            nums1[p]=nums2[j];
            p--;
            j--;
        }
    }
}
```