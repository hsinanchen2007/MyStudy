### 解题思路
入栈的：1.括号 2.括号的编号————可以算有效括号的长度
遇到‘（’ push入栈，因为必须先有左括号，左括号个数必大于右括号个数，不然非法
遇到‘）’剔除一个栈元素（因为匹配一对）
   当然这个时候要检查栈是否为空，为空的话就无法匹配，所以false
    非空就要查是否匹配，是的话就剔除栈顶

### 代码

```cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> sta;
        sta.push(-1);
        int m=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') sta.push(i);
            else{//else必然匹配，直接剔除栈顶
                sta.pop();
                if(sta.empty()) sta.push(i);//看栈如果空的话，那么刚刚不匹配，就将此时的push入栈
                else m=max(m,i-sta.top());
            }
        }
        return m;
    }
};
```