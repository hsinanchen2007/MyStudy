### 解题思路
此处撰写解题思路

### 代码

```c
int majorityElement(int* nums, int numsSize){
    int compare(const void *value1, const void *value2) {
        // 升序
        return (*(int*)value1 - *(int*)value2);
    }
    qsort(nums, numsSize, sizeof(int), compare);
    return nums[numsSize/2];
}
```