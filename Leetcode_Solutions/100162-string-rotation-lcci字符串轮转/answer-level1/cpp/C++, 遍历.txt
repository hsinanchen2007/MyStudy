

### 代码

```cpp
class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if(s1.size()!=s2.size()) return false;
        int len = s1.size();
        if(len == 0) return true;
        s1=s1+s1;
        for(int i=0;i<len;i++){
            if(s1.substr(i,len) == s2) return true;
        }
        return false;
    }
};
```