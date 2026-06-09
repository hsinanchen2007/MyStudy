### 解题思路


### 代码

```cpp
int nxt[100005];
class Solution {
public:
    string longestPrefix(string s) {
        int sz=s.size(),idx1=0,idx2=-1;
        //if(s.size()==1)return "";
        memset(nxt,-1,sizeof nxt);
        while(idx1<sz){
            if(idx2==-1||s[idx1]==s[idx2])nxt[++idx1]=++idx2;
            else idx2=nxt[idx2];
        }
        return s.substr(0,nxt[sz]);
    }
};
```