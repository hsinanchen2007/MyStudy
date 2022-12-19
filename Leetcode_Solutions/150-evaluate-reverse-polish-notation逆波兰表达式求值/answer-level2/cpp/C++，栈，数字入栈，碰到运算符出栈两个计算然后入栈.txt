### 解题思路
栈，数字入栈，碰到运算符出栈两个计算然后入栈

### 代码

```cpp
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int res=0;
        for(auto cur:tokens){
            if(cur[0]=='+'||(cur[0]=='-'&&cur.size()==1)||cur[0]=='*'||cur[0]=='/'){
                compute(s,cur[0]);
            }else {
                int num=0,flag=1;
                for(int i=0;i<cur.size();i++){
                    if(cur[i]=='-') flag=-1;
                    else {
                        num=num*10+cur[i]-'0';
                    }
                }
                num=num*flag;
                s.push(num);
            }
        }
        return s.top();
    }
    void compute(stack<int>& s,char sign){
        int a=s.top();
        s.pop();
        int b=s.top();
        s.pop();
        if(sign=='+') s.push(b+a);
        if(sign=='-') s.push(b-a);
        if(sign=='*') s.push(b*a);
        if(sign=='/') s.push(b/a);
    }
};
```