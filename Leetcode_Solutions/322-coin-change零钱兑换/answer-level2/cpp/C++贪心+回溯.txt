```cpp
class Solution {
public:
    int N;
    void ss(vector<int>& coins,int amount,int i,int n){
        if(!amount){//出口
            if(N==-1)
                N=n;
            else
                N=min(N,n);
            return;
        }
        if((i==coins.size())||(N>=0&&N<=n+amount/coins[i]))//当遍历到数组末尾或可以确定此次遍历非最优解，则返回
            return ;
        if(amount<coins[i]){//当未分配的零钱少于当前面值，直接下一层递归，然后返回
            ss(coins,amount,i+1,n);
            return;
        }
        int m=amount/coins[i];//m为当前零钱可以分配当前面值的最大个数
        amount%=coins[i];//amount为当前最小剩余零钱数
        for(int j=m;j>=0;j--){
            ss(coins,amount,i+1,n+j);
            amount+=coins[i];
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        reverse(coins.begin(),coins.end());
        N=-1;
        ss(coins,amount,0,0);
        return N;
    }
};
```
