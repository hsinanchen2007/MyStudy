### 解题思路
此处撰写解题思路

### 代码

```c
int maxProfit(int* prices, int pricesSize){
   int left = prices[0] ,income = 0 , i = 0;
   for( i=1; i < pricesSize ; i++)
   {
       if(prices[i] - left > 0)
       {
           income+= prices[i] - left ;
           left = prices[i] ;
       }
       else{
           left = prices[i] ;
       }
   }
   return income ;
}
```