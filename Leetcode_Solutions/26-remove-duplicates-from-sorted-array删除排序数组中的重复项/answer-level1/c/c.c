### 解题思路
此处撰写解题思路
1、需考虑numSize为1和0的情况；
2、只有当数不一样的时候，才需要进行长度加1，并且进行数组赋值；

### 代码

```c
int removeDuplicates(int* nums, int numsSize){
    int real_num = 0;
    int i = 0;

    if(numsSize)
    {
        real_num = 1;
    }

    for(i = 1; i < numsSize; i++)
    {
        if(nums[i] != nums[real_num - 1])
        {
            real_num++;
            nums[real_num - 1] = nums[i];
        }
    }

    return real_num;
}
```