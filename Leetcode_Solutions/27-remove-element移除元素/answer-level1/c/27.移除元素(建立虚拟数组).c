### 解题思路
建立虚拟数组，对符合要求的数组重新装填到虚拟数组中

### 代码

```c
int removeElement(int* nums, int numsSize, int val){
    int i = 0,index = 0;

    while(i < numsSize)
    {
        if(nums[i]!= val)
        {
            nums[index] = nums[i];
            index++;
        }
        i++;
    }
    return index;
}
```