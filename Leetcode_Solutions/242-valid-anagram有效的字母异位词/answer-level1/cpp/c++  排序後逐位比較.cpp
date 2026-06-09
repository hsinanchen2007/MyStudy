### 解题思路
先判斷位數是否相等，防止溢出，然後逐位比較，如果每一位都一樣返回true,否則flase

### 代码

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        for(int i=0;i<s.size();i++)
            if(s[i]!=t[i]) return false;
        return true;

    }
};
```