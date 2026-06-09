遇到左括号时，如果栈顶配对则出栈继续，否则退出，注意特殊情况。
```
class Solution {
public:
    bool isValid(string s) {
        stack<char> rightBracket;
        if(s.length() == 1)  return false;
        for(int i=s.length()-1; i>=0; i--)
        {
            if(s[i]== ')' || s[i] == ']' || s[i] == '}')
            {
                rightBracket.push(s[i]);
            }
            else{
                if(rightBracket.size() == 0)  return false;
                else
                {
                    if((s[i]=='(' && rightBracket.top() != ')') 
                    || (s[i]=='[' && rightBracket.top() != ']') 
                    || (s[i]=='{' && rightBracket.top() != '}') ) 
                        return false;
                    else rightBracket.pop();
                }
            }
        }
        if(rightBracket.size() != 0) return false;
        else  return true;
    }
};
```
