### 解题思路
双指针，一个新增无重复的元素，一个向后扫描，略过重复元素，将非重复元素加入前一指针的下一个位置
### 代码

```c
int removeDuplicates(int* nums, int numsSize){
    if (numsSize == 0) return 0;
    int len = 0;
    for ( int i = 0; i < numsSize; i++)
    {
        if (nums[len] != nums[i])   
            nums[++len] = nums[i];
    }
    return ++len;
}
```