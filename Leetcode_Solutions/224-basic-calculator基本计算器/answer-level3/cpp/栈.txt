### 解题思路
入栈:遇到字符'(' ，入栈前面计算结果(result)和计算符号(sign)
出栈:遇到字符')' ，出栈前面计算结果(result)和计算符号(sign)
并且维护一个值、操作符、结果值
### 代码

```cpp
class Solution {
public:
    int calculate(string s) {
        stack<int> tStack;
        int length = s.length();
        int opevalue = 0;
        int sign = 1;
        int result = 0;
        for(int i=0; i<length; i++){
            if(s[i] >= '0' && s[i] <= '9'){
                opevalue = opevalue*10 + (s[i] - '0');
            }
            if(s[i] == '+'){
                result += sign*opevalue;
                sign = 1;
                opevalue = 0;
            }
            if(s[i] == '-'){
                result += sign*opevalue;
                sign = -1;  
                opevalue = 0;          
            }
            if(s[i] == '('){
                tStack.push(result);
                tStack.push(sign);  
                //初始化
                sign = 1;
                result = 0;        
            }
            if(s[i] == ')'){
                result += sign*opevalue;
                sign = tStack.top(); tStack.pop();
                opevalue = tStack.top(); tStack.pop();
                result = opevalue+sign*result;

                opevalue = 0;
                sign = 1;
            }
        }
        return result+sign*opevalue;
    }
};
```