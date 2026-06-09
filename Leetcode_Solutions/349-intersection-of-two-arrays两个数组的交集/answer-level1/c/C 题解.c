- 预处理：分别对两个数组用qsort排序，简化处理
- 同时遍历比较两个数组，思路很简单，小的那一方下标++，相等则找到交集
- 这个题里要求的是结果中每个元素唯一，所以需要注意去重，可以在找到相等元素时判断一下当前结果数组里是否已经有这个元素，这里我是另写了一个find函数，感觉还能优化

`执行用时 : 8 ms, 在所有 c 提交中击败了87.67%的用户
 内存消耗 : 7.6 MB, 在所有 c 提交中击败了9.73%的用户`

```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #define max(a, b) ((a) > (b) ? (a) : (b))
int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
int find(int *nums, int len, int target)
{
    for(int i = 0; i < len; i++)
    {
        if(nums[i] == target)
        {
            return i;
        }
    }
    return -1;
}
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int len = max(nums1Size, nums2Size);
    int *res = (int *)malloc(sizeof(int) * len);
    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);
    int i = 0;
    int j = 0;
    int cur = 0;
    while(i < nums1Size && j < nums2Size)
    {
        if(nums1[i] < nums2[j])
        {
            i++;
        }
        else if(nums1[i] > nums2[j])
        {
            j++;
        }
        else
        {
            if(find(res, len, nums1[i]) == -1)
            {
                res[cur++] = nums1[i];
                
            }
            i++;
            j++;
        }
    }
    *returnSize = cur;
    return res;
}
```
