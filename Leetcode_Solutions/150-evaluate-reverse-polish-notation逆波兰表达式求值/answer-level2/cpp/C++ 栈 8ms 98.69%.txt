### 解题思路
遍历过程中: 
1. 数字直接进栈
2. 运算符弹出两个数字计算后压栈, 注意计算的顺序
![K`2ZP_2RT\]E}R0@BSUVGHPB.png](https://pic.leetcode-cn.com/a465f34fd54b03ffe932ccb8d3855283e03bd4bf90f63d2d8940ad7e46a59e51-K%602ZP_2RT%5DE%7DR0@BSUVGHPB.png)


### 代码

```cpp
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // 栈
        stack<int> _stack;
        for (auto token : tokens) {
            if (token.size() > 1 or (token[0] >= '0' and token[1] <= '9')) {
                _stack.push(atoi(token.c_str()));
                continue;
            }
            int b = _stack.top(); _stack.pop();
            int a = _stack.top(); _stack.pop();
            switch (token[0]) {
                case '+': {
                    _stack.push(a + b);
                    break;
                }
                case '-': {
                    _stack.push(a - b);
                    break;
                }
                case '*': {
                    _stack.push(a * b);
                    break;
                }
                case '/': {
                    _stack.push(a / b);
                    break;
                }
            }
        }
        return _stack.top();
    }
};
```