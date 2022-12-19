### 解题思路
执行结果：通过

执行用时 :60 ms, 在所有 C 提交中击败了10.49%的用户
内存消耗 :6.8 MB, 在所有 C 提交中击败了100.00%的用户
s
### 代码

```c
bool checkPossibility(int* nums, int numsSize){
    int temp = 0;
    int j;
    int tempNum;
    for(int i = 0;i<numsSize - 1;i++)
    {
        if(nums[i] > nums[i+1])
        {
            tempNum = nums[i];
            nums[i] = nums[i+1];
            j = i;
            break;
        }
    }
    for(int i = 0;i<numsSize - 1;i++)
    {
        if(nums[i] <= nums[i+1])
        {
            temp++;
        }
    }
    if(temp == numsSize - 1)
    {
        return true;
    }
    else
    {
        nums[j] = tempNum;
        nums[j+1] = tempNum;
    }
    temp = 0;
    for(int i = 0;i < numsSize-1;i++)
    {
        if(nums[i] <= nums[i+1])
        {
            temp++;
        }
    }
    if(temp == numsSize - 1)
    {
        return true;
    }
    else
        return false;
    

    return 0;

}
```