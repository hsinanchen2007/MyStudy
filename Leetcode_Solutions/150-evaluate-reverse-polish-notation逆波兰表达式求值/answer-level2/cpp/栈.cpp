科班出身的话，这题目应该算作Easy.
```
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int a, b;
        for(const auto &e:tokens){
            if(e.length()==1 && ispunct(e[0])){
                b=s.top(); s.pop();
                a=s.top(); s.pop();
                switch(e[0]){
                    case '+':s.push(a+b);break;
                    case '-':s.push(a-b);break;
                    case '*':s.push(a*b);break;
                    case '/':s.push(a/b);break;
                }
            }
            else s.push(atoi(e.c_str()));
        }
        return s.size()?s.top():0;
    }
};
```
