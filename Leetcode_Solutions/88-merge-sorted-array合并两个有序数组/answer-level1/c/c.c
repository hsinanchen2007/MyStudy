### 解题思路
此处撰写解题思路
1、从后往前，取最大值保存；

### 代码

```c
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int max_size = m + n;
    m--;
    n--;
    int i = 0;

    for(int i = (max_size - 1); i >= 0; i--)
    {
        if((m >= 0) && (n >= 0))
        {
            if(nums1[m] >= nums2[n])
            {
                nums1[i] = nums1[m];
                m--;
            }
            else
            {
                nums1[i] = nums2[n];
                n--;
            }
        }
        else if((n >= 0))
        {
            nums1[i] = nums2[n];
            n--;
        }
    }
}
```