两点：
1. s中出现过的同一字符，要映射到t中相同的字符
2. s中第一次出现的字符，不能映射到t中已经被映射过的字符
```
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> record;
        unordered_set<char> mapped; // 用于记录字符串 t 中已经被映射过了的字符
        for (int i = 0; i < s.size(); i++) {
            if (record.find(s[i]) == record.end()) { // 当前字符s[i]第一次出现时，则 '尝试' 为其建立映射，但不一定会成功
                if (mapped.find(t[i]) == mapped.end()) { // s[i]想要映射到t[i]，并且t[i]没有被别人映射过
                    record[s[i]] = t[i]; // s[i] ---> t[i]
                    mapped.insert(t[i]); // 标记t[i]为已被映射过的字符
                } else // 当前字符s[i]想要映射到的那个字符t[i]，已经被别的字符映射过了
                    return false;
            } else { // s[i] 之前已经建立过了映射
                if (t[i] != record[s[i]])
                    return false;
            }
        }
        return true;
    }
};
```

