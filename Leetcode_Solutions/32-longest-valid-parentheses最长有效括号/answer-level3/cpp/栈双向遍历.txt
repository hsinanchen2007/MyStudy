### 解题思路
借助栈遍历一次字符串，对未能处理的收尾子字符串反向遍历

### 代码

```cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        int num=0,maxnum=0;
        stack<int> par;
        int a=0;
        for(int i=0;i<s.size();++i){
            if(s[i]=='(') {
                par.push('(');
                ++a;
            }
            else{
                if(a==0){
                    maxnum=max(num,maxnum);
                    num=0;
                    while(par.size()>0) {par.pop();}
                    continue;
                }
                else {
                    par.push(')');
                    num+=2;
                    --a;
                }
            }
        }
        a=0;
        num=0;
        while(par.size()>0){
            if(par.top()==')') {++a;par.pop();}
            else{
                if(a==0){
                    num=0;
                    par.pop();
                    continue;
                }
                else {
                    --a;
                    par.pop();
                    num+=2;
                    maxnum=max(num,maxnum);
                }
            }
        }
        return maxnum;
    }
};
```