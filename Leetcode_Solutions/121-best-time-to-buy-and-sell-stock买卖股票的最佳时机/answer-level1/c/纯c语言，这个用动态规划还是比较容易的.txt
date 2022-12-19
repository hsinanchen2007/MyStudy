### 解题思路

### 代码

```c
//动态数据归划

int maxProfit(int* prices, int pricesSize)
{
if(pricesSize==0) return NULL;
int*a=(int*)malloc(sizeof(int)*pricesSize);
a[0]=0;
int i;
for(i=1;i<pricesSize;i++)
    {
        if(prices[i]>prices[i-1])
        a[i]=a[i-1]+prices[i]-prices[i-1];
        else if(prices[i]-prices[i-1]+a[i-1]>0)
        a[i]=prices[i]-prices[i-1]+a[i-1];
        else a[i]=0;
    }
int maxnums=a[0];
for(i=1;i<pricesSize;i++)
    {
        if(a[i]>maxnums) maxnums=a[i];
    }
return maxnums;
}
```