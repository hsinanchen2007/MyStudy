### 解题思路

字符串处理，原地算法。

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0;
        int j = 0;
        
        // reverse the string
        while(i < n) {
            while(j < n && s[j] != ' ')
                j++;
            reverse(s.begin() + i, s.begin() + j);
            while(s[j] == ' ') {
                j++;
            }
            i = j;
        }
        reverse(s.begin(), s.end());
        
        // trim spaces
        i = j = 0;
        bool isHead = true;
        while(j < n) {
            while(j < n && s[j] == ' ') {
                j++;
            }
            if(j < n && !isHead)
                s[i++] = ' ';                 // only one space left between words
            while(j < n && s[j] != ' ') {
                s[i++] = s[j++];
                isHead = false;
            }
        }
        s.erase(s.begin() + i, s.end());
        
        return s;
    }
};
```

执行用时 :4 ms, 在所有 C++ 提交中击败了98.19% 的用户
内存消耗 :9.7 MB, 在所有 C++ 提交中击败了80.01%的用户