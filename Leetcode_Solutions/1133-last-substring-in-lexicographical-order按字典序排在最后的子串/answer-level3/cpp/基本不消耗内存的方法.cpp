### 解题思路

### 代码

```cpp
class Solution {
public:
    //front > back --> return true
    bool biggerStringIndex(int m, int n, string& s) {
        int i = m, j = n; 
        while (j < s.size() && i != n) {
            if (s[++i] > s[++j])
                return true;
            if (s[i] < s[j])
                return false; 
        }
        return true;
    }

    string lastSubstring(string s) {
        int s_len = s.size(), max_index = s_len - 1;
        for (int i = s_len - 2; i >= 0; i--) {
            if (s[i] > s[max_index])
                max_index = i;
            else if (s[i] == s[max_index]) {
                if (biggerStringIndex(i, max_index, s))
                    max_index = i;
            }
        }
        return s.substr(max_index, s_len - max_index);
    }
};
```