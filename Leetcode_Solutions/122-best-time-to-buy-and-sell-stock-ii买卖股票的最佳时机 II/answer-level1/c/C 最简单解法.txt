时间O(n)空间O(1)
e...


```c
int maxProfit(int* prices, int pricesSize){
    int i,t,s=0;
    for(i=1;i<pricesSize;i++){
        t = prices[i] - prices[i-1];
        if(t > 0) s += t;
    }
    return s;
}
```