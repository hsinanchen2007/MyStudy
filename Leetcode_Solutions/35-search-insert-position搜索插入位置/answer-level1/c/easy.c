### 解题思路
此处撰写解题思路

### 代码

```c
int searchInsert(int* nums, int numsSize, int target){
    int i = 0;
    while(i < numsSize){
        if(target <= nums[i]) return i;
        else i++;
    }

    return i;
}
```