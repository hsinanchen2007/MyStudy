## 思路
**注意**
- 判断是否为数字不能用 isdigit()
- 将string转为 int
### 代码
```c++
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int size = tokens.size();
        stack<int> st;
        for (int i = 0; i < size; ++i) {            
            string s = tokens[i];
            if (s != "+" && s != "-" && s != "*" && s != "/") {
                st.push(stoi(s));
            } else {    
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                int tmp;
                if (s == "+") {                    
                    tmp = num2 + num1;
                } else if (s == "-") {
                    tmp = num2 - num1;
                } else if (s == "*") {
                    tmp = num2 * num1;
                } else if (s == "/") {
                    tmp = num2 / num1;
                } 
                st.push(tmp); 
            }
        }
        return st.top();
    }
};
```
