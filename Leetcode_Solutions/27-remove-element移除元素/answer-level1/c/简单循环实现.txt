### 解题思路
此处撰写解题思路

### 代码

```c
int removeElement(int* nums, int numsSize, int val){
    if(nums == NULL || numsSize < 1)
    return 0;
    int i,j;
    j = 0;
    for(i = 0;i < numsSize;i++)
    {
        if(nums[i] != val)
        {
            nums[j++] = nums[i];
        }
    }
    return j;
}
```