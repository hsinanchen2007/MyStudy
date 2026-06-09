### 解题思路
只需要遍历一遍数组即可，在我们遍历数组的过程中，只需要记录下s[i]之前的最小值min，以及卖出的最高价max和s[i]-min比较即可

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0)
        {
            return 0;
        }
      int max=0;
      int min=prices[0];
        for(int i=1;i<n;i++)
        {
            max=prices[i]-min>max?prices[i]-min:max;
           if(prices[i]<min)
           {
               min=prices[i];
           }
        }
         return max;
    }
};
```