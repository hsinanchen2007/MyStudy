[c++] 双指针模板


```cpp
bool checkInclusion(string t, string s) {
    int count[256] = { 0 };
    for (auto c : t) count[c]++;
    for (int len = 0, l = 0, r = 0; r < s.length(); ++r) {
        if (--count[s[r]] >= 0) ++len;
        while (r - l + 1 > len) if (++count[s[l++]] > 0) --len;
        if (len == t.length()) return true;
    }
    return false;
}
```
