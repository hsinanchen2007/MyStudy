### 解题思路
根据逆波兰表示法，求表达式的值。

有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

说明：

整数除法只保留整数部分。
给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
示例 1：

输入: ["2", "1", "+", "3", "*"]
输出: 9
解释: ((2 + 1) * 3) = 9

需要注意几个点：
（1）每个数可能是负数；
（2）减法和除法存在次序问题；
（3）正数字符串转化为整数：num= 0；for() num = num*10+ s[i]-'0';

### 代码

```cpp
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto c:tokens){
            if(c.back()>='0'&&c.back()<='9'){
                int num = 0;
                int flag = 1;
                for(auto n:c) {
                if(n=='-') flag = -1;
                else num = num*10+n-'0';
                }
                st.push(flag*num);
            }
            else{
                int a = 0;
                if(c.back()=='+'&&st.size()>=2){
                    a = st.top();  st.pop();
                    a +=st.top();st.pop();
                }
                if(c.back()=='-'&&st.size()>=2){
                    a = st.top();st.pop();
                    a=st.top()-a;st.pop();
                }
                if(c.back()=='*'&&st.size()>=2){
                    a = st.top();st.pop();
                    a=st.top()*a;st.pop();
                }
                if(c.back()=='/'&&st.size()>=2){
                    a = st.top();st.pop();
                    a=st.top()/a;st.pop();
                }
                st.push(a);
            }
        }
        return st.top();
    }
};
```