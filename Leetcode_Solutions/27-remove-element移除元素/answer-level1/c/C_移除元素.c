### 解题思路
一个写位，一个读位，读位向后迭代
    读位上的数不是要指定的数
        写到写位上，写位后移

### 代码

```c
int removeElement(int* nums, int numsSize, int val){
    int length=0;
    for(int iter=0;iter<numsSize;++iter)
        if(nums[iter]!=val)
            nums[length++]=nums[iter];
    return length;
}
```