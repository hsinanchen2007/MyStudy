![image.png](https://pic.leetcode-cn.com/6625e5e9814c60f390af506849f3ab04f7fd6e45abfdbe1b7bfcc75f1efcbb5c-image.png)


```c++
class Solution {
public:
    string::size_type findFirst(const string& s, char c, string::size_type start) {
        while (start <= s.size() / 2) { // s若包含重复子串，最少有2个子串，则第一个字符的重复的位置最大为s.size() / 2
            if (s[start] == c && (s.size() % start == 0)) { return start; } // s.size() % start 必须为0才能有整数个子串
            start++;
        }
        return string::npos;
    }

    bool canRepeat(const string& s, string::size_type subLen) {
        for (string::size_type i = 1; i < s.size() / subLen; i++) {
            for (string::size_type j = subLen * i, k = 0; j < subLen * (i + 1); ) {
                if (s[j++] != s[k++]) { return false; }
            }
        }
        return true;
    }

    bool repeatedSubstringPattern(string s) {
        if (s.empty()) { return false; }
        size_t subLen = findFirst(s, s[0], 1);
        while (subLen != string::npos) {
            if (canRepeat(s, subLen)) { return true; }
            subLen = findFirst(s, s[0], subLen + 1);
        }
        return false;
    }
};
```
