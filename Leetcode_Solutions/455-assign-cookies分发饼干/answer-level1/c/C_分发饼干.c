### 解题思路
题目设定：每个小朋友只能吃一个饼干。所以不能两个饼干凑成一个小朋友的胃口。
1给小朋友和饼干从小到大排序
2每次只喂饱饭量最小的小朋友即可。因为如果一块饼干喂不饱饭量最小的小朋友，它就不能喂饱任何一个小朋友，所以这是“没用的饼干”。如果没有能喂饱饭量最小的小朋友的饼干，统计一下有几个小朋友吃饱了即可。
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
int findContentChildren(int* g, int gSize, int* s, int sSize){
    sort(g,0,gSize-1);
    sort(s,0,sSize-1);
    int result=0,gIter=0,sIter=0;
    while(gIter<gSize&&sIter<sSize)
        if(g[gIter]<=s[sIter])
        {
            ++result;
            ++gIter;
            ++sIter;
        }
        else
            ++sIter;
    return result;
}
```