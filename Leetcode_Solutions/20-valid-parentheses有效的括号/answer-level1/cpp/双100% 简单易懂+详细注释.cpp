if-else连用有点绕，核心在于列举各可能性后逐一排除法分析

### 代码

```cpp
class Solution {
public:
    bool isValid(string s) {
//字符串为奇数必不匹配
        if(s.size() % 2 !=0) return false; 

        stack <char> sta;
        for(int i=0;i<s.size();i++){
//左括号们 欢迎入栈 
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){ 
                sta.push(s[i]);
//右括号，栈空，不匹配 
            }else if(sta.size()==0){        
                return false;
//右括号，栈非空且与栈顶匹配。抵消弹栈。
            }else if(s[i] == sta.top()+1 || s[i] == sta.top()+2){ 
                sta.pop();
//右括号，栈非空但与栈顶不匹配。错误      
            }else{              
                return false;
            }
        }

//栈空为真
        if(sta.size()==0)  return true;
        return false;    
    }
};
```