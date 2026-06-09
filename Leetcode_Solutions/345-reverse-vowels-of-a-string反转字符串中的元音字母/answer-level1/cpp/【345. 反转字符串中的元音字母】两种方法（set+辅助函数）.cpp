### 思路一：set

### 代码
```c++
class Solution {
public:
    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;
        set<char> st{'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
        while (left < right) {
            if (st.count(s[left]) > 0 && st.count(s[right]) > 0) {
                swap(s[left], s[right]);
                ++left, --right;
            }
            if (st.count(s[left]) == 0) {
                ++left;
            }
            if (st.count(s[right]) == 0) {
                --right;
            }
        }
        return s;
    }
};
```

### 思路一：辅助函数

### 代码

```cpp
class Solution {
public:
    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;        
        while (left < right) {
            if (isVowel(s[left]) && isVowel(s[right])) {
                swap(s[left], s[right]);
                ++left, --right;
            }
            if (!isVowel(s[left])) {
                ++left;
            }
            if (!isVowel(s[right])) {
                --right;
            }
        }
        return s;
    }
    bool isVowel(const char c) {
        return c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U';
    }
};
```