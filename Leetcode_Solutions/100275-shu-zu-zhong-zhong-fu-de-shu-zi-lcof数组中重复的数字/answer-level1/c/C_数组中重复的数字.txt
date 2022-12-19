### 解题思路
先排序再查重会超时。直接hash表法。

### 代码

```c
int findRepeatNumber(int* nums, int numsSize){
    int* hash=(int*)malloc(sizeof(int)*numsSize);
    for(int i=0;i<numsSize;++i)hash[i]=0;
    for(int i=0;i<numsSize;++i)
        if(++hash[nums[i]]>1)
        {
            free(hash);
            return nums[i];
        }
    return -1;
}
//-----------------------------------------------------下面方法是排序+查重 超时
/*void sort(int* Nums,int Low,int High)
{
    if(Low<High)
    {
        int i=Low,j=High,temp=Nums[Low];
        while(i!=j)
        {
            while(i<j&&temp<Nums[j])--j;
            if(i<j)Nums[i++]=Nums[j];
            while(i<j&&temp>Nums[i])++i;
            if(i<j)Nums[j--]=Nums[i];
        }
        Nums[i]=temp;
        sort(Nums,Low,i-1);
        sort(Nums,i+1,High);
    }
}
int findRepeatNumber(int* nums, int numsSize){
    sort(nums,0,numsSize-1);
    for(int i=0;i+1<numsSize;++i)
        if(nums[i]==nums[i+1])
            return nums[i];
    return -1;
}*/
```