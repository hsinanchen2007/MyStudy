### 解题思路

如果下一步是false，这一步就是true

### 代码

```cpp
class Solution {
public:
    unordered_map<string,bool> um;
    bool canWin(string s) {
        if(um.find(s)!=um.end())return um[s];
        bool ret=false;
        for(int i=0;i+1<s.size();i++){
            if(s[i]=='+'&&s[i+1]=='+'){
                auto tmp=s;tmp[i]='-';tmp[i+1]='-';
                if(canWin(tmp)==false){ret=true;break;}
            }
        }
        return um[s]=ret;
    }
};
```