### 解题思路

首先最优的两次买卖股票的时间至少有一次用到了总体买卖一次股票最优的起点和终点。
先向上一题一样求出买卖一次股票的最大值，并标记此时的买的时间和卖的时间。
另一次买卖只可能在这段时间之前或这段时间之后或者在这段时间之内，分别遍历，
取最大的即可。
### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i,j,k,m1,m2,l,r,n=prices.size();
        if(n==0)return 0;
        m1=0;l=r=0;j=prices[0];k=0;
        for(i=1;i<n;i++){
            if(prices[i]<=j){
                j=prices[i];
                k=i;
            }
            if(prices[i]-j>m1){
                m1=prices[i]-j;
                r=i;l=k;
            }
        }
        if(m1==0||n<4)return m1;
        m2=0;k=99999999;
        for(i=r+1;i<n;i++){//第二次买卖在右边
            k=min(k,prices[i]);
            m2=max(m2,prices[i]-k);
        }
        k=99999999;
        for(i=0;i<l;i++){//第二次买卖在左边
            k=min(k,prices[i]);
            m2=max(m2,prices[i]-k);
        }
        k=99999999;
        for(i=r-1;i>l;i--){//第二次买卖在中间
            k=min(k,prices[i]);
            m2=max(m2,prices[i]-k);
        }
        return m1+m2;
    }
};
```