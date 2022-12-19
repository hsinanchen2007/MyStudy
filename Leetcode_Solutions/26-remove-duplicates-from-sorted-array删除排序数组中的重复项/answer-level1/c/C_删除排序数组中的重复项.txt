### 解题思路
标记1：写入标记 length
标记2：探查标记 iter
标记3：数字标记 num

从头到尾探查数组
    如果 探查标记的数字 和 数字标记 不一样
        数字标记 改成 探查标记 的新数字
        把探查标记的数写到 写入标记++ 的位置
返回写入标记的

### 代码

```c
int removeDuplicates(int* nums, int numsSize){
    if(numsSize==0)
        return 0;
    int length=1,num=nums[0];
    for(int iter=0;iter<numsSize;++iter)
        if(nums[iter]>num)
        {
            num=nums[iter];
            nums[length++]=num;
        }
    return length;
}
```