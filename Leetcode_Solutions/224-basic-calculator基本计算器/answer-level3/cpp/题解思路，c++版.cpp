### 解题思路
题解思路，c++版

1.正序迭代字符串。
2.操作数可以由多个字符组成，字符串 "123" 表示数字 123，它可以被构造为：123 >> 120 + 3 >> 100 + 20 + 3。如果我们读取的字符是一个数字，则我们要将先前形成的操作数乘以 10 并于读取的数字相加，形成操作数。
3.每当我们遇到 + 或 - 运算符时，我们首先将表达式求值到左边，然后将正负符号保存到下一次求值。
4.如果字符是左括号 (，我们将迄今为止计算的结果和符号添加到栈上，然后重新开始进行计算，就像计算一个新的表达式一样。
5.如果字符是右括号 )，则首先计算左侧的表达式。则产生的结果就是刚刚结束的子表达式的结果。如果栈顶部有符号，则将此结果与符号相乘。

### 代码

```cpp
class Solution {
public:
    int calculate(string s) {
        long long res=0,num=0;  //num是目前数字
        long long  sign=1;     //保存符号
        stack<long long> st;
        for(auto c:s){
            if(c==' ') continue;

            if(c>='0'&&c<='9') {
                num=num*10+c-'0';
            }
            else if(c=='+'){
                res+=sign*num;
                sign=1;
                num=0;
            }else if(c=='-'){
                res+=sign*num;
                sign=-1;
                num=0;
            }else if(c=='('){
                st.push(res);
                st.push(sign);
                sign=1;
                res=0;
            }else if(c==')'){
                res+=sign*num;
                res*=st.top();
                st.pop();
                res+=st.top();
                st.pop();
                num=0;
            }
        }
        return int(res + (sign * num));
    }
};
```