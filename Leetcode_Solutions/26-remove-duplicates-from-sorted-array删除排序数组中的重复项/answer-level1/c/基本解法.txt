### 解题思路
双指针思路，在C中nums本身就是数组首地址指针，所以定义两个位置变量就可以标记快慢指针位置。

### 代码

```c
int removeDuplicates(int* nums, int numsSize){
    int i, j;
    if(numsSize == 0) return 0;
    for(i=0,j=0; j<numsSize; j++)
    {
        if(nums[j] != nums[i])
        {
            i++;
            nums[i]=nums[j];
        }
    }
    return numsSize = i+1;
}
```