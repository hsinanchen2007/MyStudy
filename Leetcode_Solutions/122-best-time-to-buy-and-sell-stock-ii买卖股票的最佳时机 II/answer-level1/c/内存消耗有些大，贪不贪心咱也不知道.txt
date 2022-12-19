怒力ing小白一只
执行用时 :
8 ms
, 在所有 C 提交中击败了
91.65%
的用户
内存消耗 :
7.9 MB
, 在所有 C 提交中击败了
5.09%
的用户
```
int maxProfit(int* prices, int pricesSize){
    int i=0,j;
    int profit=0;
    
    while(i<pricesSize-1)
    {
        j=i;
        while(i<pricesSize-1&&prices[i]<prices[i+1])//寻找递增子序列
        {
            i++;
        }//此时k为卖出的最好时机
        profit=profit+(prices[i]-prices[j]);
        i++;
    }
    return profit;
}
```
