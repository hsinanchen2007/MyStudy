### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isValid(string s) {
        vector<char> vStack;
        int nSize=s.size();
        if(nSize<=0)
        {
            return true;
        }
        for(int i=0;i<nSize;++i)
        {
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
            {
                vStack.push_back(s[i]);
                continue;
            }
            if(s[i]==')')
            {
                if(vStack.size()<=0)
                {
                    return false;
                }
                if(vStack[vStack.size()-1]!='(')
                {
                    return false;
                }
                vStack.pop_back();
                continue;
            }
            if(s[i]=='}')
            {
                if(vStack.size()<=0)
                {
                    return false;
                }
                if(vStack[vStack.size()-1]!='{')
                {
                    return false;
                }
                vStack.pop_back();
                continue;
            }
            if(s[i]==']')
            {
                if(vStack.size()<=0)
                {
                    return false;
                }
                if(vStack[vStack.size()-1]!='[')
                {
                    return false;
                }
                vStack.pop_back();
                continue;
            }
        }
        return vStack.size()<=0;
    }
};
```
几分钟搞定