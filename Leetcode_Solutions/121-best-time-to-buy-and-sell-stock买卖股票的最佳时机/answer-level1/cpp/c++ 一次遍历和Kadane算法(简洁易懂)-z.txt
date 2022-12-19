### 一次遍历

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice=INT_MAX ,maxprofit=0;
        for(int p:prices)       //p为当轮循环的股票价格
        {
           minprice =min (minprice,p);                     //当前的股票最低价格
           maxprofit=max (maxprofit,p-minprice);          //当前的最大利润
        }      
        return maxprofit;
    }
};
```
### Kadane算法

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sumprofit=0 ,maxprofit=0;
        for(int i=1;i<prices.size();i++)       
        {
           sumprofit += prices[i]-prices[i-1];  
           sumprofit  = max(0,sumprofit);       //当sumprofit小于0时，此时的prices[i]为目前的最小值,应重新考虑此时买入
           maxprofit  = max(maxprofit,sumprofit);
        }      
        return maxprofit;
    }
};


```

### 暴力

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        int max=0;
        for(int i=0;i<len;i++)
        for(int j=i+1;j<len;j++)
            if(prices[j]-prices[i]>max)
            max=prices[j]-prices[i];

        return max;
    }
};
```