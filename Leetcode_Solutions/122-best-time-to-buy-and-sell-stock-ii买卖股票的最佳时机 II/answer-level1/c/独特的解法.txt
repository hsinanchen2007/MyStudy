### 解题思路
每一个谷底到谷峰之间的差值均为收益,最大收益为所有差值之和;
设置两个变量,l和h;
当曲线下降时,l和h一起下降;
当曲线上升时,l留在原地,h独自上升;
这样就能得到每一个差值,所有差值相加即为最大收益.

### 代码

```c

int maxProfit(int* prices, int pricesSize){

    if(pricesSize==0)return 0;

    int l=prices[0];
    int h=prices[0];
    int sum=0;
    for(int i=0;i<pricesSize;i++)
    {
        if(prices[i]>h) //上升时,h自己上升;
            h=prices[i];
        if(prices[i]<h) //下落时,l和h一起下落;当l和h一起下落时,代表到了谷峰,计算此时的差值;
        {
            int d=h-l;  //计算谷峰和谷底差值;
            sum+=d;

            l=prices[i];
            h=prices[i];
        }
    }
    int d=h-l;
    sum+=d;
    return sum;

}




```