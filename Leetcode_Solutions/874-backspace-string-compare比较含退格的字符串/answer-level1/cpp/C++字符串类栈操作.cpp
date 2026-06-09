执行用时 0 ms, 
在所有 C++ 提交中击败了100.00%的用户
```cpp []
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string s1 = "";
        string s2 = "";
        for(char c : S)
            if(s1.size() && c=='#')
                s1.pop_back();
            else if(c!='#')
                s1 += c;
        for(char c : T)
            if(s2.size() && c=='#')
                s2.pop_back();
            else if(c!='#')
                s2 += c;
        return s1==s2;
    }
};
```