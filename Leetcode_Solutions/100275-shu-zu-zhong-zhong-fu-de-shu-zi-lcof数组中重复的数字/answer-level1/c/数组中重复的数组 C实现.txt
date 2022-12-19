### 解题思路
此处撰写解题思路
1、排除边界
2、下标0~n 存的数字0~n
3、假设：没有重复数字，则所有数字可以与下标形成一一对应关系
    否则，某些会空出某些数字
3、扫描将下标i与对每个数字m对比，相等不动继续下一个，不等判断下标i与m数字是否相等，不等则换位子，再次判断下标i与m对应数字是否相等，直到找到下标和数字m相等。在这个过程中，扫描下标为m的数字并判断。
### 代码

```c

int findRepeatNumber(int* nums, int numsSize){
    int tmp = 0;
    int i = 0;
    
       
    if((nums == NULL)||(numsSize <= 0))
        return -1;

    for(i = 0; i < numsSize; i++)
    {
        if((nums[i] < 0)||(nums[i] > numsSize - 1))
            return -1;
    }
  
    for(int i = 0; i < numsSize; i++)
    { 
        while(i != nums[i])
        {
            if(nums[nums[i]] == nums[i])
            {
                return nums[i];
            }
            tmp = nums[i];
            nums[i] = nums[tmp];
            nums[tmp] = tmp;
        }
    }
    
    return -1;
}

```