遇到数字入栈，遇到符号出栈两次，计算，结果入栈，最后取栈顶元素即为结果，除法一般需要判分母是否为0，但是这题数据都为合法值
```
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        unordered_map<char, function<int(int, int)>> mapping = {
            {'+', [](int x, int y) {return x + y;}},
            {'-', [](int x, int y) {return x - y;}},
            {'*', [](int x, int y) {return x * y;}},
            {'/', [](int x, int y) {return x / y;}}
        };
        for (auto i : tokens) {
            if (i == "+" || i == "-" || i == "*" || i == "/") {
                int a = s.top(); s.pop(); int b = s.top(); s.pop();
                s.push(mapping[i[0]](b, a));
            } else {
                s.push(stoi(i));
            }
        }
        return s.top();
    }
};
```