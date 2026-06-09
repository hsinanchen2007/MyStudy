### 解题思路
突破口：S+S的[-1:1]中必有原S串

### 代码

```cpp
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if( (s+s).substr(1,2*s.length()-2).find(s) != string::npos )
            return true;
        return false;
    }
};
```