### 解题思路
C ，双下标，在一次循环的过程中实现判断修改
一个下标每次循环判断与下一个元素是否相同
不同
将下一个元素传给P2所指//可能P1+1与p2是同一个
相同
P1++


### 代码

```c
int removeDuplicates(int* nums, int numsSize)
{
    //伪代码
    //设置双指针，同时遍历
    //一个指向需要判断的位置
    //一个指向可以修改的位置
    int p1=0;
    int p2=1;
    int i=1;
    if(numsSize!=0)
    {
        for(int i=1;i<=numsSize-1;i++)
        {
            if(nums[p1]!=nums[p1+1])
            {
                p1++;
                nums[p2]=nums[p1];
                p2++;
            }
            else
            {
                p1++;
            }
        }
        return p2;
    }
    else
    {
        return 0;
    }
}
```