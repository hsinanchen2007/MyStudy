```
class StockSpanner {
public:
    stack<vector<int>> s;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        int scale = 1;
        while (!s.empty() && *s.top().begin() <= price)
        {
            scale += s.top()[1];
            s.pop();
        }
        
        s.push({price, scale});

        return scale;
    }
};
```
