### 解题思路
使用栈方法。栈ind存储无法转换成有效子串的下标。
对字符串遍历：
（1）如果当前字符s[i]=='('：直接将其下标i压栈
（2）如果当前字符s[i]==')'：看栈顶对应的下标在s中是不是左括号，即s[ind.top()]=='('，如果是则出栈；如果不是，即栈为空或栈顶对应下标的字符是右括号，则将当前下标i压栈。

遍历完成后得到了保存非有效子串的字符下标。从后往前，即从栈顶往栈底计算前后两个下标值的差再减一，得到两下标之间的有效子串的长度。并保存最长长度。
注意因为字符串末尾可能属于有效子串部分而不被压栈，所以在计算开始前将字符串s的长度压栈，即尾字符的后一位。
遍历栈元素时，满足栈中至少有两个元素可比较。在遍历完成后，还要将栈中剩余的最后一个元素与0进行做差得到“以0为有效子串最左下标的串长度”。

栈方法还有动态规划方法都应注意边缘的情况处理。。

### 代码

```cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        int len=s.length();
        if(len<2){
            return 0;
        }
        stack<int>ind;  //存储下标
        for(int i=0;i<len;i++){
            if(s[i]=='('){
                ind.push(i);
            }
            else{
                if(!ind.empty()&&s[ind.top()]=='('){
                    ind.pop();
                }
                else{
                    ind.push(i);
                }
            }
        }
        ind.push(len);
        int Max=0;
        while(ind.size()>1){
            int t1=ind.top();
            ind.pop();
            int t2=ind.top();
            t1=t1-t2-1;
            Max=Max>=t1?Max:t1;
        }
        int t=ind.top();
        Max=Max>=t?Max:t;
        return Max;
    }
};
```