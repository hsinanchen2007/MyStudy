### 解题思路
-   将 正序两元素最大正向差 转换为 相邻元素差之和，之后的思路与求最大子序列和一样
即:a[j]-a[i]=(a[j]-a[j-1]) + (a[j-1]-a[j-2]) +...+ (a[i+1]-a[i] ) （ j>i ）
- 举例:a[5]-a[2]=(a[5]-a[4]) + (a[4]-a[3]) + (a[3]-a[2]) 
### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
              if(prices.empty())//这一步很重要，
              return 0;
              int nowMax=0;
              int Max=0;
              for(int i=0;i<prices.size()-1;i++) //相邻元素的差一共有 price.size() -1 个
              {
                  nowMax=max(prices[i+1]-prices[i],nowMax+prices[i+1]-prices[i]);
                  Max=max(Max,nowMax);//维护最大值
              }
              return Max;
            }
        
        
    
};
```