### 解题思路
此处撰写解题思路

### 代码

```c
static int m_cmp(const void *x, const void *y)
{
    return (*(int *)x - *(int *)y);
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    memcpy(nums1 + m, nums2, sizeof(int) * n);
    qsort((void *)nums1, m + n, sizeof(int), m_cmp);
}
```

方法二：双指针移动


### 代码

```c
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int idx1 = m - 1;
    int idx2 = n - 1;
    int idx = m + n - 1;
    int i;

    while (idx2 >= 0 && idx1 >= 0) {
        if (nums1[idx1] > nums2[idx2]) {
            nums1[idx] = nums1[idx1];
            idx1--;
        } else {
            nums1[idx] = nums2[idx2];
            
            idx2--;
        }
        idx--;
    }

    while (idx2 >= 0) {
        nums1[idx2] = nums2[idx2];
        idx2--;
    }
}
```