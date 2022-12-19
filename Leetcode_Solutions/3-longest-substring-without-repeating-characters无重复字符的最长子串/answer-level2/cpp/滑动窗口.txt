### 解题思路
滑动窗口

### 代码
```cpp
int lengthOfLongestSubstring(string s) {
    if(s.empty()) return 0;
    vector<int> pos(128, -1);
    int l = 0, r = 0, maxLen = 1;
    while(r != s.length()) {
        if(pos[s[r]] == -1)
            maxLen = max(maxLen, r - l + 1);
        else {
            while(l != pos[s[r]]) {
                pos[s[l]] = -1;
                ++l;
            }
            pos[s[l]] = -1;
            ++l;
        }
        pos[s[r]] = r;
        ++r;
    }
    return maxLen;
}
```