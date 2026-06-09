### 解题思路
个人用堆栈法解的，nums里面比target小的数入栈，最后判断栈的情况即可；注意栈头

### 代码

```c
int searchInsert(int* nums, int numsSize, int target)
{
int i;
int count=-1;
int*mark=(int*)malloc(sizeof(int)*numsSize);
for(i=0;i<numsSize;i++)
    {
        if(nums[i]<target)
            {
                mark[++count]=nums[i];
            }
    }
if(count==-1)
return 0;
return (count+1);
}
```