```
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i=0; i<tokens.size(); i++) {
            string c = tokens[i];
            if(c != "+" && c != "-" && c != "*" && c != "/") {
                s.push(stoi(c));
            }
            else{
                int num1 = s.top(); s.pop();
                int num2 = s.top(); s.pop();
                if(c == "+") {
                    s.push(num1 + num2);
                }
                else if(c == "-") {
                    s.push(num2 - num1);
                }
                else if(c == "*") {
                    s.push(num1 * num2);
                }
                else if(c == "/") {
                    s.push(num2 / num1);
                }
            }
        }
        return s.top();
    }
};
```
