### 解题思路
深度为n的内层括号的分数为2^n（n从0开始）
栈存储每个（的深度
当遇到）如果是当前最深深度或者比当前深度（程序用**in**变量）深，则计算分数
>此条件是为了防止重复计算
### 代码

```cpp
class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> s;
        int in=0;
        int score=0;
        for(int i=0;i<S.size();i++){
            if(S[i]=='('){
                if(s.empty()) s.push(0);
                else s.push(s.top()+1);
                continue;
            }
            else{
                //in表示最内层括号，如果存在同级括号或者更高一级的括号计算
                if(s.top()>=in){
                    score+=pow(2,s.top());
                }
                printf("%d ",in);
                in=s.top();
                s.pop();
                
            }
            
    
        }
        return score;

    }
};
```