优先级从右向左，因此反向遍历字符串，可用两个栈分别记录操作（?的前一个字符）和值，当值有两个且有一个操作时，执行三元运算。
```
string parseTernary(string expression) {
        stack<char> op;
        stack<char> val;
        for (int i = expression.length() - 1; i >= 0; --i) {
            if (isdigit(expression[i]) || expression[i] == 'T' || expression[i] == 'F') {
                val.push(expression[i]);
            } else if (expression[i] == '?') {
                --i;
                op.push(expression[i]);
            }
            while (val.size() >= 2 && op.size() >= 1) {
                char c = op.top();
                op.pop();
                char val1 = val.top();
                val.pop();
                char val2 = val.top();
                val.pop();
                if (c == 'T') {
                    val.push(val2);
                } else {
                    val.push(val1);
                }
            }
        }
        return string(1, val.top());
    }
```