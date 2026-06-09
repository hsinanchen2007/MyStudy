1.将加减转换为数字前的符号位，整个式子变成多个数字相加；
2.遇到左括号将之前的结果和后面数字的符号进栈；
3.遇到右括号将栈顶符号弹出与新的数字相乘，再与栈顶数字相加得到新的计算结果；
4.遇到数字将一串字符相加为string类字符串，再通过stoi()库函数转为数字可以防止数字溢出。

    int calculate(string s) {
        int result=0,sign=1,i;
        string num;
        stack<int> st;
        for(i=0;i<s.size();i++){
            if(s[i]=='+'){
                sign=1;
            }
            else if(s[i]=='-'){
                sign=-1;
            }
            else if(s[i]=='('){
                st.push(result);
                st.push(sign);
                result=0;
                sign=1;
            }
            else if(s[i]==')'){
                result*=st.top();
                st.pop();
                result+=st.top();
                st.pop();
            }
            else if(s[i]<='9'&&s[i]>='0'){
                for(num="";i<s.size()&&s[i]<='9'&&s[i]>='0';i++){
                    num+=s[i];
                }
                i--;
                result+=stoi(num)*sign;
            }
        }
        return result;
    }