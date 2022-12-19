### 解题思路
此处撰写解题思路

### 代码

```c
int Compare(int* a, int* b) 
{
    return *a - *b;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int*   nums;
    int total = nums1Size + nums2Size;

    if (total == 0) {
        return (double)0;
    }
    
    nums = (int *)malloc(sizeof(int) * (nums2Size + nums1Size));
    memset(nums, 0, sizeof(int) * (nums1Size + nums2Size));
    
    for (int i = 0; i < nums1Size; i++) {
        nums[i] = nums1[i];
    }
    for (int j = 0; j < nums2Size; j++) {
        nums[nums1Size + j] = nums2[j];
    }

    qsort(nums,nums2Size + nums1Size, sizeof(int),Compare);
    if ((nums1Size + nums2Size) % 2) {
        return (double)nums[total/2];
    } else {
        return (double)(nums[total/2] + nums[total/2 -1])/2;
    }
}
```