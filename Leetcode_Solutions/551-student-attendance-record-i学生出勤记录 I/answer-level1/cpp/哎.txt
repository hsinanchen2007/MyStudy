### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool checkRecord(string s) {
        int a1=0,a2=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='A'){
                a1++;
            }
            if(a1>1)return false;
            if(s[i]=='L'){
                if(i+1<s.length()&&s[i+1]=='L'){
                    if(i+2<s.length()&&s[i+2]=='L'){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
```