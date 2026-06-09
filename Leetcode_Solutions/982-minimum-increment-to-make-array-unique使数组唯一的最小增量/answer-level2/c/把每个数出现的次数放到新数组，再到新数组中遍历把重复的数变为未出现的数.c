### 解题思路
讲讲容易坑的点;
1、当A数组大小为0时返回空
2、当A数组大小为1时返回0
3、在统计了每个数字出现的次数时，需要同时用count来记录之后索要操作的次数。当count为0时说明原数组为唯一数组所以直接返0
4、A里面包含了0，所以设置新数组时需要考虑。同时最坑的是，新数组的大小要原数组最大的两倍，即80000
因为一题目没有说增加后的数一定要在0到40000范围内，题目只要求的是原来给定的A数组是这个范围。、
二是如果给定的A数组大小为40000，同时每个数都是40000，那就需要把除第一个的所有数都增加。所以40000大小是不够的，是需要80000
很大很大的缺点就在此，因为数组空间太大，所以消耗空间很多

### 代码

```c
int minIncrementForUnique(int* A, int ASize){
    if(ASize==0)
    return NULL;
    if(ASize==1)
    return 0;
    int *nums=(int *)malloc(sizeof(int)*80000);
    memset(nums,0,sizeof(int)*80000);
    int count=0;
    for(int i=0;i<ASize;i++){
        nums[A[i]]++;
        if(nums[A[i]]>=2)
        count++;
    }
    if(count==0)
    return 0;
    int tick=0;int j=0;int diff=0;
    for(int i=0;i<80000;i++){
        if(nums[i]>1){
            tick=i;
            break;
        }
    }
    j=tick+1;
    while(count!=0&&j<80000){
        if(nums[j]==0){
            count--;
            diff+=j-tick;
            nums[tick]--;
            if(nums[tick]==1){
                while(nums[tick]<=1&&count!=0){
                    tick++;
                }
                if(tick>j)
                j=tick;
            }
        }
        j++;
    }
    return diff;
}
```