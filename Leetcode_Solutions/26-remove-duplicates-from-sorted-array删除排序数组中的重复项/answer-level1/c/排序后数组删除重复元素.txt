### 解题思路
开始报内存溢出，需要考虑数组中只有一个数，没有数的情况，否则越界

### 代码

```c
int removeDuplicates(int* nums, int numsSize){
int i,j;
int numsSize2=1;
if(numsSize==1)
    return numsSize2;
if(numsSize==0)
    return 0;

for(i=0,j=1;j<numsSize;j++)
{
    if(nums[i]!=nums[j])
    {
        nums[i+1]=nums[j];
        i++;
        numsSize2++;
    }
}
return numsSize2;
}
```