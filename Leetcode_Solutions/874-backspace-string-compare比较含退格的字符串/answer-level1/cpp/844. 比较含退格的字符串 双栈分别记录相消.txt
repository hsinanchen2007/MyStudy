### 解题思路
此处撰写解题思路

### 代码

```cpp
//双栈分别记录
//# pop 其余 push
//最后弹栈相消

//# 且为empty时，则忽视
#include <stack>
#include <string>
class Solution {
private:
    stack<int> sStk, tStk;
public:
    bool backspaceCompare(string S, string T) {
        for(int i = 0; i < S.size(); i++){
            if('#' == S[i]){
                if(sStk.empty()){
                    continue;
                }
                else{
                    sStk.pop();
                }
            }
            else{
                sStk.push(S[i]);
            }
        }

        for(int i = 0; i < T.size(); i++){
            if('#' == T[i]){
                if(tStk.empty()){
                    continue;
                }
                else{
                    tStk.pop();
                }
            }
            else{
                tStk.push(T[i]);
            }
        }    

        while(!sStk.empty() && !tStk.empty()){
            if(sStk.top() != tStk.top()){
                return false;
            }
            sStk.pop();
            tStk.pop();
        }   

        if(sStk.empty() && tStk.empty()){
            return true;
        }else
            return false;
    }
};
```