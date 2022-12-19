```
class Solution{
public:
    bool isValid(string s){
        stack<char> tmp;
        //如果是空字符串，也可以
        if(s.empty()) return true;
        //奇数个，直接排除
        if(s.size()%2==1) return false;
        for(int i=0;i<s.size();i++){
            //左括弧入栈
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
                    tmp.push(s[i]);

            }else{
                //全是右括弧
                if(tmp.empty()) return false;
                //遇到右括弧，出栈，栈顶元素和左元素配对
                if(s[i]==')'&&tmp.top()!='('||s[i]==']'&&tmp.top()!='['||s[i]=='}'&&tmp.top()!='{'){
                    return false;
                }
                   tmp.pop();
            }

        }

        //如果没有遇到右括弧
        return tmp.empty();

    }
};
```
