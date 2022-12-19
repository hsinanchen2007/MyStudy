我是用一个栈trof来存在操作，包括其状态；（定义了4种状态，T0,T1,F0,F1）
后缀表示：
0:操作为T/F,且还未遇到其对应的':'前面的值
1:操作为T/F,已经遇到其对应的':'前面的值
用栈stk_left存放当前值
```
class Solution {
public:
    string parseTernary(string expression) {
        //stk_left存放值，trof存放操作
        stack<string> stk_left,trof;
        expression+=':';
        string temp="",next="";
        for(int i=0;i<expression.size();i++){
            //遇到'?'需要入栈当前的操作
            if(expression[i]=='?')
                trof.push(temp+expression[i-1]+"0");
            else if(expression[i]==':'){
                while(!trof.empty()){
                    string& cur_opt=trof.top();
                    if(cur_opt=="T0"||cur_opt=="F0"){
                        if(cur_opt=="T0")
                            stk_left.push(next==""?temp+expression[i-1]:next);
                        if(cur_opt=="F0")
                            next="";
                        cur_opt=(cur_opt=="T0"?"T1":"F1");
                        break;
                    }
                    if(cur_opt=="T1"&&!stk_left.empty()){
                        next=stk_left.top();
                        stk_left.pop();
                    }   
                    if(cur_opt=="F1"){
                        if(next=="")
                            next=expression[i-1];
                    }
                    trof.pop();
                }
            }
        }
        return next;
    }
};
```
