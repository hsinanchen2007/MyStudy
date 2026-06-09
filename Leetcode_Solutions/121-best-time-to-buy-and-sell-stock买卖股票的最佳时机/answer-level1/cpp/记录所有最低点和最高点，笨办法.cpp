重点是一直记录可获得的最大利润，出现更低买点时更新买点。
我这方法不好。
```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) return 0;
    vector<int> low,high;
    if(prices[0]<prices[1]) low.push_back(prices[0]);
    
    for(auto it=prices.begin()+1;it<prices.end()-1;it++){
        if(*it>*(it-1) && *it >=*(it+1) && !low.empty()) high.push_back(*it);
        else if(*it<=*(it-1) && *it <*(it+1)) low.push_back(*it);
    }
    if(*(prices.end()-1)<=*(prices.end()-2)) low.push_back(*(prices.end()-1));
    else high.push_back(*(prices.end()-1));
    if(high.empty()) return 0;
    int m=low.size();
    int n=high.size();
    int max=0;
    for(int i=0;i<m;i++){
        for(int j=i;j<n;j++){
            if(high[j]-low[i]>max) max=high[j]-low[i];
        }
    }
    return max;
    }
};
```
