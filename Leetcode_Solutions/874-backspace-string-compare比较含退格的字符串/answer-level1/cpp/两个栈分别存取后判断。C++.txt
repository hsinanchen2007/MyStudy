### 解题思路
NULL

### 代码

```cpp
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        if(S.size()==0&&T.size()==0) return true;
        stack<char> sts;
        stack<char> stt;
        for(int j = 0;j<S.size();j++)
        {
            if(S[j]!='#')
            {
                sts.emplace(S[j]);
            }
            else if(sts.empty()) continue;
            else sts.pop();
        }
        for(int i = 0;i<T.size();i++)
        {
            if(T[i]!='#')
            {
                stt.emplace(T[i]);
            }
            else if(stt.empty()) continue;
            else stt.pop();
        }
        if(sts.empty()&&stt.empty())return true;
        if(sts.empty()||stt.empty()) return false;
        if(sts.size()!=stt.size()) return false;
        while(!sts.empty())
        {
            if(sts.top()!=stt.top()) return false;
            sts.pop();
            stt.pop();
        }
        return true;


    }
};
```