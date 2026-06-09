### 解题思路
此处撰写解题思路
暴力法，但是牵涉到重复比较的问题，会出现次数多。所以应对原始数组先排序，再比较如果存在交集，则同时跳过比较下一个。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 void sort(int *nums, int numsSize){
     int temp;
     for(int i = 0; i < numsSize; i++){
         for(int j = i + 1; j < numsSize; j++){
             if(nums[i] > nums[j]){
                 temp = nums[i];
                 nums[i] = nums[j];
                 nums[j] = temp;
             }
         }
     }
 }
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
     //先采用下面的方法，发现会重复
     //应与元素在两个数组中出现的次数一致。 满足不了这个条件
     //先对2组数据排序
     //相等时，数组1直接到下一值，数组2则跳到当前的下一个不再重头来
    int *res;
    int k = 0;
    *returnSize = 0;

    sort(nums1, nums1Size);
    sort(nums2, nums2Size);

    if(nums1Size > nums2Size){
        res = (int *)malloc(sizeof(int) * nums2Size);
        for(int i =0; i < nums2Size; i++){
            for(int j = k; j < nums1Size; j++){
                if(nums2[i] == nums1[j]){
                    res[*returnSize] = nums2[i];
                    (*returnSize)++;
                    k = j + 1;
                    break;
                }
            }
        }
    }
    else{
        res = (int *)malloc(sizeof(int) * nums1Size);
        for(int i =0; i < nums1Size; i++){
            for(int j = k; j < nums2Size; j++){
                if(nums1[i] == nums2[j]){
                    res[*returnSize] = nums1[i];
                    (*returnSize)++;
                    k = j + 1;
                    break;
                }
            }
        }
    }
        
    return res;

}
```