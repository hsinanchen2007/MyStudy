![Snipaste_2019-12-04_17-09-37.png](https://pic.leetcode-cn.com/99bc49a65189d0b8da1fbe65c9da75af917c053798029d3bba152c4d983ef458-Snipaste_2019-12-04_17-09-37.png)


```
class StockSpanner {
    stack<pair<int, int>> stock;
public:
    StockSpanner() {
        stock = stack<pair<int, int>>();
    }
    
    int next(int price) {
        if (stock.empty()) {
            stock.push(make_pair(price, 1));
            return 1;
        }
        int ret = 1; 
        while(!stock.empty() && stock.top().first <= price) {
            ret += stock.top().second;
            stock.pop();
        }
        stock.push(make_pair(price, ret));
        return ret;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
```
