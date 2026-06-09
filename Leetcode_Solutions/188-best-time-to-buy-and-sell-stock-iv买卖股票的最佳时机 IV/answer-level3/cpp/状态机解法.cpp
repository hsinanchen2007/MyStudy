```cpp
//状态机解法
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.empty()||k==0)  return 0;
        // k的优化，非常重要，过大的k无意义并且会引起内存超限
        if(k>prices.size()/2) k=prices.size()/2+1;    //这里加1是为了防止k=1/2=0的情况
        vector<int> s(2*k,INT_MIN);
        s[0]=-prices[0];
        for(int p:prices){
            //state1 第一次买入
            s[0]=max(s[0],-p);
            s[1]=max(s[1],s[0]+p);
            for(int i=1;i<k;++i){
                s[2*i]=max(s[2*i],s[2*i-1]-p);
                s[2*i+1]=max(s[2*i+1],s[2*i]+p);
            }
        }
        return max(0,s.back());
    }
};
```
