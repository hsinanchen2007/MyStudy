典型单调栈题型，prices 序列是未知的，暴力一点可以保存以往的每个 price 以及维护 index 变量。使用 pair<int, int> 可以节省不必要的空间浪费。很自然地想到 pair<index, price>，官方题解使用了 pair<weight, price>，学习一下。

***Talk is cheap. Show me the code.***
```
class StockSpanner {
private:
    stack<pair<int, int>> stk; // <weight, price>
    
public:
    StockSpanner() {
    }
    
    int next(int price) {
        int weight = 1;
        while (!stk.empty() && price >= stk.top().second) {
            weight += stk.top().first;
            stk.pop();
        }
        stk.push(make_pair(weight, price));
        return weight;
    }
};
```
