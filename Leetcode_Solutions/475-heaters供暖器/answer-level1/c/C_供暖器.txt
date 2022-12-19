### 解题思路
先排序
lastLeft是指房子i最左边的暖气heaters[lastLeft]，房子i+1寻找从 heaters[lastLeft]~房子i+1右边的第一个暖气位置 之间的暖气
找出每个房子和与其最近（最小值）的暖气距离
取所有距离的最大值


参考
作者：ikaruga
链接：https://leetcode-cn.com/problems/heaters/solution/heaters-by-ikaruga/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
### 代码

```c
int abs(int Num)
{
    return Num>0?Num:Num*(-1);
}
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

int findRadius(int* houses, int housesSize, int* heaters, int heatersSize){
    sort(houses,0,housesSize-1);
    sort(heaters,0,heatersSize-1);
    int lastLeft=0,maxDistance=0;
    for(int i=0;i<housesSize;++i)
    {
        int distance=(~((unsigned)0))>>1;
        for(int j=lastLeft;j<heatersSize;++j)
        {
            lastLeft = houses[i] >= heaters[j] ? j : lastLeft;
            distance = distance<abs(houses[i]-heaters[j])?distance:abs(houses[i]-heaters[j]);
            if (houses[i] < heaters[j]) break;
        }
        maxDistance=maxDistance>distance?maxDistance:distance;
    }
    return maxDistance;
}
```