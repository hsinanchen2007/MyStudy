设一stack用于插入顺序，一map用于排序

代码：
```
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    multimap <int, int> m;
    
    MinStack() {
    }
    
    void push(int x) {
        s.push(x);
        m.insert(pair<int, int>(x, 1));
    }
    
    void pop() {
        int temp = s.top();
        s.pop();
        for (map<int, int>::iterator it = m.begin() ; it != m.end(); it++) {
            if (it->first == temp) {
                m.erase(it);
                break;
            }
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return m.begin()->first;
    }
};

```
