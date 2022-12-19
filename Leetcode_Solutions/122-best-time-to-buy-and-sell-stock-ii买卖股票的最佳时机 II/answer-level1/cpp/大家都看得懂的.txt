从第一天开始有赚就赚（也就是如果第二天比第一天贵，第一天就买），
第三天如果比第二天还贵，在第二天的时候再卖出。
如果后一天比前一天便宜（赚不到），就不再买入，等到下一天比前一天贵时再买入。

总的来说，就是你眼中只有两天，今天和明天，你只要保证明天的时候自己可以赚钱就可以。
那就可以保证每天都赚钱。

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0){
            return 0;
        }
        int sum=0;
        for(int i=0;i<prices.size()-1;i++){
            if(prices[i]<prices[i+1]){
                sum=prices[i+1]-prices[i]+sum;
            }
        }
        return sum;
    }
};