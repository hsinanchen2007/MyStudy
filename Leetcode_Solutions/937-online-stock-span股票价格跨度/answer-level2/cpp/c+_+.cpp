### 解题思路

![image.png](https://pic.leetcode-cn.com/a60d2207ec31c98a88a130734edb4a2ade9853f195f2e93ed0e1243d4f3b45d8-image.png)

### 代码

```cpp
class StockSpanner {
public:
    vector<int> arr;
    stack<int> s;
    int st, ed;
    StockSpanner() {
        st = -1, ed = 0;
        arr = vector<int>();
    }
    
    int next(int price) {
        int ans = 1;
        arr.push_back(price);
        ed = arr.size() - 1;
        while(s.size() && arr[s.top()] <= price) s.pop();//寻找左面第一个比当前大的
        if(s.size()){ 
            st = s.top();
            ans = ed - st;
        }
        else ans = arr.size();
        s.push(ed);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
```