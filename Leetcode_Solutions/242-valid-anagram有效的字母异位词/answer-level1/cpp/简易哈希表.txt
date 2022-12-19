### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isAnagram(string s, string t)
    {
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        for (auto c : s)
            cnt[c - 'a']++;
        for (auto c : t)
            cnt[c - 'a']--;
        for (int i = 0; i < 26; i++)
            if (cnt[i] != 0) return 0;
        return 1;
    }
};
```