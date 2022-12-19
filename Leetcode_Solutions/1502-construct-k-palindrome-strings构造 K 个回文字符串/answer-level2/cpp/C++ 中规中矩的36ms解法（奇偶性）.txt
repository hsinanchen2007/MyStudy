### 代码
```cpp
class Solution {
public:
    bool canConstruct(string s, int k) {
        int cnt[26] = { 0 }, odd = 0;
        for (char ch : s) ++cnt[ch - 'a'];
        for (int c : cnt) if (c & 1) ++odd;
        
        return (odd <= k && k <= (int)s.size());
    }
};
```