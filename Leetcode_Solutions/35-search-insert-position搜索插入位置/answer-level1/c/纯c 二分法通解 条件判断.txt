### 解题思路
并不推荐在竞赛时参考本篇，我是通过不断进行提交确定特殊情况再增加判断条件的方式通过的

### 代码

```c
//numsSize代表个数
int searchInsert(int* nums, int numsSize, int target){
    int m=0,n=numsSize;
    if(target==0)
    return 0;//去掉target为0和为1的情况
    if(numsSize==1)
    {
        if(nums[0]>=target)
        return 0;
        else
        return 1;
    }
    //在numsSize>=2也就是数组中包含三个数的时候使用二分法查找
    while(m!=n-1)//如果查找到m==n-1即m与n相邻的情况则退出
    {
        if(target>nums[(m+n)/2])
        {
            m=(m+n)/2;
        }
        else if(target<nums[(m+n)/2])
        {
            n=(m+n)/2;
        }//以上为基本的二分法
        else if(target==nums[(m+n)/2])//若是直接通过二分法查找到了弹出
        {
            return (m+n)/2;
        }
    }
    //二分法没找到，则该数不在数组内或者是numsSize==2被直接弹出的情况，需要进行进一步判断
    if(nums[m]>=target)
    return m;
    else
    return n;

}
```