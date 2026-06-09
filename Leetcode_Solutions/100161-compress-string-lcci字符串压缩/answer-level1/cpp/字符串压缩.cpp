### 解题思路
注意to_string()的使用

### 代码

```cpp
class Solution {
public:
    string compressString(string S) {
        if(S.length()<=2)
            return S;
        string s1;
        int m=0;
        s1+=S[0];
        char temp = S[0];
        for(int i=0;i<S.length();i++){
            if(S[i] == temp){
                m++;
            }else{
                s1 += to_string(m);
                s1 += S[i];
                m=1;
                temp = S[i];
            }
        }
        s1 += to_string(m);
        if(s1.length()>S.length())
            return S;
        return s1;
        
    }
};
```