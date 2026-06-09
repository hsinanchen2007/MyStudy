```
int comp(const void *a,const void *b)
{
return *(int*)a-*(int*)b;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//借鉴了评论区大佬的解答  再加上一点自己的想法
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    //returnSize为返回的值
    *returnSize = 0;
    if(nums1Size == 0 || nums2Size == 0) {
        return NULL;
    }
    //排序
    qsort(nums1,nums1Size,sizeof(int),comp);
    qsort(nums2,nums2Size,sizeof(int),comp);
    int data[nums1Size>nums2Size?nums1Size:nums2Size];//临时储存数组
    for(int i=0; i < nums1Size; i++){
        if(i!=nums1Size-1&&nums1[i]==nums1[i+1])//去重
            continue;
        for(int j=0;j<nums2Size;j++){
            if(j!=nums2Size-1&&nums2[j]==nums2[j+1])//去重
            continue;
            if(nums1[i]==nums2[j]){
                data[(*returnSize)++]=nums1[i];
            }
        }
    }
    
     int * arr=(int *)malloc((*returnSize)*sizeof(int));
     memcpy(arr,data,(*returnSize)*sizeof(int));//从第0个字符开始复制，连续复制*returnSize个
    
    return arr;
}
```