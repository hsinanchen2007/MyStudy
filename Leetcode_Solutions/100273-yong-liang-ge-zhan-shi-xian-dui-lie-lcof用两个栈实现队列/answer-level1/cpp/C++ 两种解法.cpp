### O(1)进队, O(n)出队
```cpp
class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        in.push(value);
    }
    
    int deleteHead() {
        if (in.empty() && out.empty()) return -1;
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
        int top = out.top();
        out.pop();
        return top;
    }
    
private:
    stack<int> in;
    stack<int> out;
};
```

### O(n)进队, O(1)出队
```cpp
class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        while (!main_stk.empty()) {
            sup_stk.push(main_stk.top());
            main_stk.pop();
        }
        main_stk.push(value);
        while (!sup_stk.empty()) {
            main_stk.push(sup_stk.top());
            sup_stk.pop();
        }
    }
    
    int deleteHead() {
        if (main_stk.empty()) return -1;
        int top = main_stk.top();
        main_stk.pop();
        return top;
    }
    
private:
    stack<int> main_stk;
    stack<int> sup_stk;
};
```