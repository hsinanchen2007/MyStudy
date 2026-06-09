### 解题思路
此处撰写解题思路

### 代码

```c
bool canJump(int* nums, int numsSize){
    bool result;
    int i;
    int good=numsSize-1;
    for(i=numsSize-2;i>=0;i--)
    {
        if(nums[i]>=good-i)
        {
            good=i;
        }
    }
    if(good==0)
    {
        return true;
    }else
    {
        return false;
    }
}
```