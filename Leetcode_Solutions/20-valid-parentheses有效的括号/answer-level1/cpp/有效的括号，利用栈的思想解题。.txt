思路 用vector模拟栈空间，使用charKsI指针移动控制栈顶。

```
class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 1) return false;
        if(s.size() == 0) return true;
        vector<char> charKs(s.size(), 0);
        int charKsI = 0;
        for(int sS = 0; sS < s.size(); sS++){
            if(s[sS] == '(' || s[sS] == '{' || s[sS] == '['){
                charKs[charKsI] = s[sS];
                charKsI++;
            }else{
                if(charKsI == 0) return false;
                else{
                    if(s[sS] == ')'){
                        if(charKs[charKsI-1] != '(') return false;
                    }else if(s[sS] == '}'){
                    if(charKs[charKsI-1] != '{') return false;
                    }else{
                        if(charKs[charKsI-1] != '[') return false;
                    }
                    charKsI--;
                }
            }
        }
        if(charKsI == 0) return true;
        else return false;
    }
};
```
