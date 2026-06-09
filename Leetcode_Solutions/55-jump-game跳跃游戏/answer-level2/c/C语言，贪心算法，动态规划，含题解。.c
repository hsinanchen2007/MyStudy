### 解题思路
此处撰写解题思路

### 代码

```c
//自顶向下的动态规划，寻找能到达顶端的最左边的点，判断是不是开始处。
/*bool canJump(int* nums, int numsSize){
    bool result;
    int i;
    int good=numsSize-1;//good点处为目前能到达目标点的最右边的点
    for(i=numsSize-2;i>=0;i--)
    {
        if(nums[i]>=good-i)//如果成立，则说明能到达后边的good点，即能通过此点到目标点。
        {
            good=i;//更新good点。
        }
    }
    if(good==0)
    {
        return true;
    }else
    {
        return false;
    }
}*/
//贪心算法，通过遍历寻找能到达的最右边的点
bool canJump(int* nums,int numsSize)
{
    int i;
    int *emon;
    int maxstep=0;
    emon=(int *)malloc(sizeof(int)*numsSize);
    for(i=0;i<numsSize-1;i++)
    {
        emon[i]=i+nums[i];
    }
    for(i=0;i<numsSize-1;i++)
    {
        if(emon[i]>maxstep)
        {
            maxstep=emon[i];
        }
        if(i>=maxstep)
        {
            break;
        }
    }
    if(maxstep>=numsSize-1)
    {
        return true;
    }else
    {
        return false;
    }
}
```