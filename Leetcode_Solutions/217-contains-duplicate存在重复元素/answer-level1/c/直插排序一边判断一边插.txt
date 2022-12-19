### 解题思路
用直接插入排序对整个数组进行插入
分三种情况：
大于 继续查询
小于 进行插入
等于 返回true

### 代码

```c
bool containsDuplicate(int* nums, int numsSize){
     int temp=0,i=0,j=0,k=0;
    for(i=1;i<numsSize;i++)
    {
        temp=nums[i];
        for(j=i-1;j>=0;j--)
        {
            if(nums[j]>temp)
                nums[j+1]=nums[j];
            if(nums[j]==temp)
                return true;
            if(nums[j]<temp)
                break;
        }
            nums[j+1]=temp;
    }
    return false;
}
```