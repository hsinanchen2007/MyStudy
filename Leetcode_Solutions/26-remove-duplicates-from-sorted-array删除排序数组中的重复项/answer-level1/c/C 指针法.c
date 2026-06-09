### 解题思路
利用额外的一个指针flag=0。对数组进行扫描，初始时将nums[0]设置为temp，当扫描到的数字和temp不相同时，将temp写入到nums[flag],并将flag+1，以此类推，直到数组末尾。

执行用时 :20 ms, 在所有 C 提交中击败了96.68%的用户
内存消耗 :8.3 MB, 在所有 C 提交中击败了100.00%的用户

### 代码

```c
int removeDuplicates(int* nums, int numsSize)
{
    if(numsSize==0)
        return 0;
    int flag=0;
    int temp=nums[0];
    for(int i=1;i<numsSize;i++)
    {
        if(nums[i]!=temp)
        {
            nums[flag]=nums[i-1];
            flag++;
            temp=nums[i];
        }
    }
    nums[flag]=nums[numsSize-1];
    return flag+1;
}
```