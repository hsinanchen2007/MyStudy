### 解题思路
此处撰写解题思路

### 代码

```c
int searchInsert(int* nums, int numsSize, int target){
    int i;
    while(i < numsSize && nums[i] < target) i++;
     return i;
}
```