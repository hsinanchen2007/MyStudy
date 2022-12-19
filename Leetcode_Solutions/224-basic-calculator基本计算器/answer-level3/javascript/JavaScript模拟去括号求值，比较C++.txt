测试了一下，同样的解题方法，去括号按顺序求值。
用C++写，力扣得分为：
 * 执行用时 :16 ms, 在所有 C++ 提交中击败了93.43%的用户
 * 内存消耗 :10.5 MB, 在所有 C++ 提交中击败了69.92%的用户

用JavaScript写，力扣得分为：
 * 执行用时 :112 ms, 在所有 JavaScript 提交中击败了88.14%的用户
 * 内存消耗 :36.8 MB, 在所有 JavaScript 提交中击败了94.12%的用户

感觉还是C++的效率快一点啊！

C++代码, 来自jakenma
```
class Solution {
public:
    int calculate(string s) {
        int sum=0;
        stack<char> stk;
        int flag=1;
        u_int num=0;
        int i=0;
        string s_("+");
        s_+=s;
        char op;
    
        while(i<s_.size()){
            if(s_[i]=='+'||s_[i]=='-')
            {
                op=s_[i];
                  
                int j=i+1;
                bool need_up=false;
                while(s_[j]<'0'||s_[j]>'9')
                {
                    if(s_[j]=='(')
                    {
                        stk.push(op);
                        need_up=true;   //延迟更新flag             
                    }
                    j++;
                }
                while(s_[j]>='0'&&s_[j]<='9')
                {
                    num=num*10+s_[j]-'0';
                    j++;
                }
                //cout<<"  "<<op<<"1*"<<flag<<"*"<<num;
                if(op=='+')
                    sum+=flag*num;
                else
                    sum-=flag*num;
                num=0;
                i=j;
                if(need_up==true&&stk.top()=='-')
                    flag*=(-1);
                continue;
            }
            if(s_[i]==')')
            {
                if(stk.top()=='-')
                    flag*=(-1);
                stk.pop();
                i++;
                continue;
            }
            i++;
        }
        return sum;
    }
};
```


JavaScript代码
```
var calculate = function(s){
    let arr = [], sum = 0, num = 0, flag = 1;
    s = "+" + s; //前面加一个+号

    for (let i = 0; i < s.length; i++){

        if (s[i] == '+' || s[i] == '-'){ //+-后面可能为数字/空格/左括号
            temp = s[i];
            let need_up = false;
            while(s[i+1] < '0' || s[i+1] > '9'){
                if (s[i+1] == '('){  //将左括号前面的符号压入栈。一个左括号匹配一个+-号
                    need_up = true;
                    arr.push(temp);
                }
                i++;
            }

            //+-号后面的数字，或者+-号后面口号里面的数字
            while(s[i+1] >= '0' && s[i+1] <= '9'){
                num = num*10 + (s[i+1] - '0'); //拼接完整数字
                i++;
            }

            if (temp == '+'){
                sum += flag * num;
            }
            else{
                sum -= flag * num;
            }
            num = 0;

            if (need_up && arr[arr.length-1] == '-'){
                flag *= (-1); //如果左括号前是-号，flag需要反转
            }
        }
        else if(s[i] == ')'){
            if (arr[arr.length-1] == '-'){
                flag *= (-1); //移除-号时，flag需要反转
            }
            arr.pop(); //碰到右括号移除一个运算符
        }
    }
    return sum;
}
```
