### 解题思路
用子集的每一个元素拿来和大集合中的元素对比，先在大集合中找到子集元素的对应位，再找出比子集元素大的第一个元素。注意越界返回-1

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int* result=(int*)malloc(sizeof(int)*nums1Size);
    *returnSize=nums1Size;
    for(int i=0;i<nums1Size;++i)
    {
        int iter=0;
        while(nums2[iter]!=nums1[i])++iter;
        while(iter<nums2Size&&nums2[iter]<=nums1[i])++iter;
        result[i]= iter==nums2Size?-1:nums2[iter];
    }
    return result;
}
```