### 解题思路
先插入排序在逐次比较

### 代码

```c
bool containsDuplicate(int* nums, int numsSize){
    if (numsSize<2) 
    return 0;
    else{
    int temp=0,j=0,k=0;
    for(int i=1;i<numsSize;i++)
    {
        temp=nums[i];
        for(j=i-1; j>=0 && nums[j]>temp;j--)
        {
            nums[j+1]=nums[j];
        }
        nums[j+1]=temp;
    }
    while(k<(numsSize-1) && nums[k]!=nums[k+1]) k++;
    if (k<(numsSize-1)) return 1;
    else return 0;}
}
```