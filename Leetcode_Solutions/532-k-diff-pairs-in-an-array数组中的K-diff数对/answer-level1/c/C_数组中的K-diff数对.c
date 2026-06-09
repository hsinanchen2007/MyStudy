### 解题思路
先排序再比较

### 代码

```c
void sort(int* Nums,int Low,int High)
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
int findPairs(int* nums, int numsSize, int k){
    sort(nums,0,numsSize-1);

    int result=0;
    for(int i=0;i<numsSize;++i)
        for(int j=i+1;j<numsSize;++j)
            if(nums[i]+k==nums[j])//如果相等
            {
                ++result;
                while(i<numsSize&&nums[i]+k==nums[j])++i;//跳过后面相同的值,开始新的num[i]
                --i;//抵消for循环的++i
                break;
            }
    return result;
}
```