基本原理如下：
1.先找到发生逆序的起始元素，这里需要注意的是逆序是指a1,a2,如果a2小于a1，那么a1的下标的就是逆序的起始元素

2.在找到逆序的头尾之后，再寻找在逆序中的最大最小值。

3.利用子序列的最值再从两头开始寻找真正的下标。

这里发生了两次寻找下标，需要注意相同元素的判断。

```
int findUnsortedSubarray(int* nums, int numsSize){
    int posi=0,posj=numsSize-1,i,j,min,max;//游标和定位
        while(posj>posi&&nums[posi]<=nums[posi+1])posi++;//定位下标
        while(posj>posi&&nums[posj]>=nums[posj-1])posj--;
    if(posi==posj)
        return 0;
    min=nums[posi],max=nums[posj];
    for(i=posi;i<=posj;i++)//找到子数组中最大最小值
        {
        if(nums[i]<min)
            min=nums[i];
        if(nums[i]>max)
            max=nums[i];
    }
    posi=0,posj=numsSize-1;
    while(nums[posi]<=min)posi++;
    while(nums[posj]>=max)posj--;
    return posj-posi+1;
}
```

