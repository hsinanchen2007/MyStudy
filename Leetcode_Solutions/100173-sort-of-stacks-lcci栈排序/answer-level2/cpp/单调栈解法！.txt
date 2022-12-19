### 解题思路
此处撰写解题思路

### 代码

```cpp
class SortedStack {
public:

    void push(int val) {

        while (!s.empty() && s.top() < val) {
            aux.push(s.top());
            s.pop();
        }
        
        s.push(val);

        while (!aux.empty()) {
            s.push(aux.top());
            aux.pop();
        }
    }
    
    void pop() {
        if (!isEmpty()) s.pop();
    }
    
    int peek() {
        return isEmpty() ? -1 : s.top();
    }
    
    bool isEmpty() {
        return s.empty();
    }

private:
    // s 为单调递减栈. aux == auxiliary 辅助栈
    stack<int> s, aux;
};

/**
 * Your Sorteds object will be instantiated and called as such:
 * Sorteds* obj = new Sorteds();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */
```