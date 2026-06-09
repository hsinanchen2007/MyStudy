```
    class Solution {
    public:
        int getv(string &s){
            int ans = 0;
            if(s[0]=='-'){
                for(int i = 1; i < s.size(); i++) ans = ans*10+s[i]-'0';
                return -ans;
            }
            else{
                for(auto v:s) ans = ans*10+v-'0';
                return ans;
            }
        }
        int calc(int a, int b, char op){
            if(op=='+') return a+b;
            else if(op=='-') return a-b;
            else if(op=='*') return a*b;
            else return a/b;
        }
        int evalRPN(vector<string>& t) {
            stack<int> stk;
            for(auto s : t){
                if(s[0]>='0'&&s[0]<='9'||s[0]=='-'&&s.size()>1) stk.push(getv(s));
                                                        //读入数字 负数和减号需要特判
                else {//是运算符，则从栈顶弹出两个操作数 进行运算
                    int b = stk.top();
                    stk.pop();
                    int a = stk.top();
                    stk.pop();
                    stk.push(calc(a,b,s[0]));
                }
            }
            return stk.top();
        }
    };
```
