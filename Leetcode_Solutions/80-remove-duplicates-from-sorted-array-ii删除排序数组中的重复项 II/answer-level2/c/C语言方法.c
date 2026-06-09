### 解题思路
通过遍历整个数组，对重复出现的元素进行限制，出现次数不得超过两次，用old_num来保存数组中的不同元素

### 代码

```c
int removeDuplicates(int* nums, int numsSize){
    if(numsSize==0) return 0;
    if(numsSize==1) return 1;
    int old_num,i,k=0,count=0;
    old_num=nums[0];
    for(i=0;i<numsSize;i++)
    {
        if(nums[i]==old_num)
        {
            if(count<2)
            {
                nums[k]=old_num;
                k++;
                count++;
            }
        }
        else
        {
            old_num=nums[i];
            count=0;
            nums[k]=old_num;
            k++;
            count++;
        }
    }
    return k;
}
```