### 解题思路
此处撰写解题思路

### 代码

```c
void sortColors(int* nums, int numsSize){
    for(int i=0;i<numsSize;i++)
    {
        for(int j=i;j<numsSize;j++)
        {
            if(nums[j]<nums[i])
            {
                int tmp=nums[i];
                nums[i]=nums[j];
                nums[j]=tmp;
            }
        }
    }
    return nums;
    


}
```