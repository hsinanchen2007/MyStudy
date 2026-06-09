### 解题思路
没技术含量，流泪

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int i,j;
    int *result;
    result=(int *)malloc(sizeof(int)*nums1Size);
    *returnSize=nums1Size;
    for(i=0;i<nums1Size;i++){
        for(j=0;j<nums2Size;j++){
            if(nums2[j]==nums1[i]){
                j++;
                while(j<nums2Size&&nums2[j]<nums1[i]){
                    j++;
                }
                if(j==nums2Size){
                    result[i]=-1;
                }
                else{
                    result[i]=nums2[j];
                }
                break;
            }
        }
    }
    return result;
}
```