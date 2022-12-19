### 解题思路
此处撰写解题思路

### 代码

```c
int missingNumber(int* nums, int numsSize){

int sum = 0;
for(int i = 0; i <numsSize; i++)
{
    sum+=nums[i];
}
return (numsSize+1) * (numsSize )/2  - sum;
}
```