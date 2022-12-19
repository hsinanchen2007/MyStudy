### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string s,t;
        for(int i=0;i<S.length();i++){
            if(S[i]!='#'){
                s+=S[i];
            }
            else{
                if(s.length()>0){
                    s=s.substr(0,s.length()-1);
                }
                else{
                    s.clear();
                }
            }
        }
        for(int i=0;i<T.length();i++){
            if(T[i]!='#'){
                t+=T[i];
            }
            else{
                if(t.length()>0){
                    t=t.substr(0,t.length()-1);
                }
                else{
                    t.clear();
                }
            }
        }
        return s==t? true: false;
    }
};
```