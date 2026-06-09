写完代码后，看了一下别人的，基本上都是大同小异，基本上都是利用了滑动窗口或者双指针。

我觉得看题解的可能都是对双指针存在疑问的伙伴，我这里稍微讲一下用双指针的原因。

首先看题目的意思，最重要的一点就是子数组，意味着数组必须是连续的，从这一点就可以考虑用双指针了，也可以

称为滑动窗口，用滑动窗口可能更加贴切，因为窗口是连续的。

rear指向尾部，head指向头部，如果窗口内的累加值没有>=s，head继续向前，如果窗口内的已经>=s,那么可以考虑

rear前移。

这里需要注意你设置的head和rear指向的到底是什么？

```
int minSubArrayLen(int s, int* nums, int numsSize){
    int head=0,rear=0,sum=0;
    int min=numsSize+1;
    while(head<numsSize)
    {
        sum+=nums[head++];//head永远指向即将要加的元素
        while(rear<head&&(sum-nums[rear])>=s)
            {
            sum-=nums[rear++];
            }
        if(sum>=s&&(head-rear)<min)
        min=(head-rear);
    }
    if(min==numsSize+1)
    return 0;
    return min;
}
```
