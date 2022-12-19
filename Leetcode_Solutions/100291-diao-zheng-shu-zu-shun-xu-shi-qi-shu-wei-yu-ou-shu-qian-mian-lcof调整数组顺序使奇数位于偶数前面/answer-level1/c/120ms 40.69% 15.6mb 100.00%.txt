### 解题思路
为什么这么慢啊   难道大家用的不是双指针吗

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* exchange(int* nums, int numsSize, int* returnSize){
    *returnSize=numsSize;
    int i=0,j=numsSize-1;
    while(i<j){
        while(i<j&&nums[i]%2==1){
            i++;
        }
        while(i<j&&nums[j]%2==0){
            j--;
        }
        int t=nums[i];
        nums[i]=nums[j];
        nums[j]=t;
    }
    return nums;
}
```