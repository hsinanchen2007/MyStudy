```cpp
class MyQueue {
public:
    stack<int> A;
    stack<int> B;

    void A2B()
    {
        if (B.empty()) {
            while (!A.empty())
            {
                B.push(A.top());
                A.pop();
            }
        }
    }

    MyQueue() {}

    void push(int x) {
        A.push(x);
    }

    int pop() {
        A2B();
        int ans = B.top();
        B.pop();
        return ans;
    }

    int peek() {
        A2B();
        int ans = B.top();
        return ans;
    }

    bool empty() {
        return A.empty() && B.empty();
    }
};
```