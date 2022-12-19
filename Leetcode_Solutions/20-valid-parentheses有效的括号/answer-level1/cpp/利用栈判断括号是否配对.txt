### 解题思路
1.首先对空字符串和仅含有一个字符的字符串做判断
2.如果字符串中出现左侧括号"{","(","["入栈
3.如果字符串中出现右侧括号"}",")","]"则与该字符前面的字符判断(即栈顶元素),看是否能够配对,如果可以配对则将栈顶元素弹出,否则返回false
4.整个字符串判断完成后,如果最后栈为空,则表示全部配对,否则返回false

### 代码

```cpp
class Solution {
public:
    bool isValid(string s) {
        if(s.empty()){
            return true;
        }
        if(1 == s.size()){
            return false;
        }
        stack<char> tmpCharStack;
        char tmpChar;

        for(size_t i=0;i<s.size();i++){
            if('(' == s[i] || '{' == s[i] || '[' == s[i]){
                tmpCharStack.push(s[i]);
            }
            else if(')' == s[i] && !tmpCharStack.empty()){
                tmpChar = tmpCharStack.top();
                if(tmpChar != '(')
                    return false;
                else        
                    tmpCharStack.pop();
            }
            else if('}' == s[i] && !tmpCharStack.empty()){
                tmpChar = tmpCharStack.top();
                if(tmpChar != '{')
                    return false;
                else        
                    tmpCharStack.pop();
            }
            else if(']' == s[i] && !tmpCharStack.empty()){
                tmpChar = tmpCharStack.top();
                if(tmpChar != '[')
                    return false;
                else        
                    tmpCharStack.pop();
            }
            else{
                return false;
            }
        }
        if(tmpCharStack.empty())
            return true;
        else    
            return false;
    }
};
```