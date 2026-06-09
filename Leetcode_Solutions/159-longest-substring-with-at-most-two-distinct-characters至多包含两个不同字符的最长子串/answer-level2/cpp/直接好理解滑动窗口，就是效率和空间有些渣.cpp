### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int l = 0;
        int r = 0;
        int max_len = 0;
        int win_size = 0;
        for (int i = 0; i < s.length(); ++i) {
            string substr = s.substr(l, r - l + 1);
            while (getDiffChar(substr).size() > 2) {
                l++;
                substr = s.substr(l, r - l + 1);
            }
            win_size = r - l + 1;
            max_len = win_size > max_len ? win_size : max_len;
            r++;
        }

        return max_len;

    }

private:
    set<char> getDiffChar(string s)
    {
        set<char> char_set;
        for (int i = 0; i < s.length(); ++i) {
            char_set.insert(s[i]);
        }
        return char_set;
    }
};
```