### 解题思路
用一个stack来储存，遇到运算符就把前两个数算好。
需要注意的是负数的情况，要单独判断一下
### 代码

```cpp
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (int i=0; i<tokens.size(); i++) {
            switch (tokens[i][0]) {
                case '+':
                {
                    int a = stk.top();
                    stk.pop();
                    int b = stk.top();
                    stk.pop();
                    stk.push(b+a);
                    break;
                }
                case '*':
                {
                    int a = stk.top();
                    stk.pop();
                    int b = stk.top();
                    stk.pop();
                    stk.push(b*a);
                    break;
                }
                case '/':
                {
                    int a = stk.top();
                    stk.pop();
                    int b = stk.top();
                    stk.pop();
                    stk.push(b/a);
                    break;
                }
                case '-':
                {
                    if (tokens[i].size()==1) {
                        int a = stk.top();
                        stk.pop();
                        int b = stk.top();
                        stk.pop();
                        stk.push(b-a);
                        break;
                    }
                }
                default:
                    stk.push(stoi(tokens[i]));
            }  
        }
        return stk.top();
    }
};
```