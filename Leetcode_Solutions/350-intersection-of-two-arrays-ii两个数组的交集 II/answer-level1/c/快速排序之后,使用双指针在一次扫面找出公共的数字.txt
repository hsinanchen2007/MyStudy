### 解题思路
双指针，找公共切面 2333

### 代码

```c


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void insertSort(int* nums, int numsSize)
{
    int i, j, temp;
    for(i=1; i<numsSize; i++) {
        temp=nums[i];
        for(j=i; j>0; j--) {
            if(temp<nums[j-1]) {
                nums[j]=nums[j-1];
            }else{
                break;
            }
        }
        nums[j]=temp;
    }
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    insertSort(nums1,nums1Size);
    insertSort(nums2,nums2Size);
    int i=0, j=0, cnt=0;
    int min; 
    min = (nums1Size<nums2Size)?nums1Size:nums2Size;
    int *p = (int*)malloc(min * sizeof(int));
    while (i<nums1Size&&j<nums2Size){
        if (nums1[i]<nums2[j]) i++;
        else if (nums1[i]>nums2[j]) j++;
        else {
            p[cnt++] = nums1[i];
            i++; j++;
        }
    }
    *returnSize = cnt;
    return p;
    
}


```