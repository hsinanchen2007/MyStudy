### 解题思路
利用辅助栈求逆波兰表达式
通俗易懂

### 代码

```cpp
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> S;
        int result = 0;
        int i,j;
        for(auto& str : tokens)
        {
            if(str == "*" ||str == "/" ||str == "+" ||str == "-"){
                i = S.top();
                S.pop();
                j = S.top();
                S.pop();
                if(str == "+")
                {                        
                    result = i + j;
                    S.push(result);
                }
                if(str == "-")
                {                        
                    result = j - i;
                    S.push(result);
                }
                if(str == "*")
                {                        
                    result = i * j;
                    S.push(result);
                }
                if(str == "/")
                {                        
                    result = j / i; //注意顺序不要弄反哦
                    S.push(result);
                }               
            }           
            else 
            {
                S.push(atoi(str.c_str()));
            }
        }
        return S.top();
    }
};
```