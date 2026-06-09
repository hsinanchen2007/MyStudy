### 解题思路
从后往前覆盖。

### 代码

```c
void moveZeroes(int* nums, int numsSize){
    int size=numsSize;
    for(int i=0;i<size;)
    {
        if(nums[i]==0)
        {
            for(int j=i;j<numsSize-1;j++)
            {
                nums[j]=nums[j+1];
            }
            size--;
        }
        else
        i++;
    }
    for(int i=size;i<numsSize;i++)
    nums[i]=0;
}
```