```c++
class StockSpanner {
public:
    vector<int> prices;
    stack<int> s;
    vector<int> ans;
    StockSpanner() {
    }
    int next(int price) {
        prices.push_back(price);
        int ret = prices.size() - 1;
        while(!s.empty() && prices[s.top()] <= price){
            ret = ans[s.top()];
            s.pop();
        }
        s.push(prices.size() - 1);
        ans.push_back(ret);
        return prices.size() - ret;
    }
};
```
