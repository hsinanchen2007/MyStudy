```
class Solution {
public:
    bool isNumber(string s) {
        bool has_dot = false;
        bool has_e = false;
        bool has_front_num = false;
        int i = 0;
        // skip front space
        while (s[i] == ' ') ++i;
        // check first char
        if (s[i] == '.') {
            has_dot = true;
        } else if (s[i] >= '0' && s[i] <= '9') {
            has_front_num = true;
        } else if (s[i] != '+' && s[i] != '-') {
            return false;
        }
        ++i;
        // check char before 'e'
        while (i < s.size() && ((s[i] >= '0' && s[i] <= '9') || 
                (has_front_num && !has_e && s[i] == 'e') ||
                (!has_e && !has_dot && s[i] == '.'))) {
            if (s[i] == 'e') {
                has_e = true;
                ++i;
                break;
            } else if (s[i] == '.') {
                has_dot = true;
            } else {
                has_front_num = true; 
            }
            ++i;
        }
        // check after 'e'
        if (has_e) {
            if (i >= s.size())
                return false;
            bool has_tail_num = false;
            if (s[i] >= '0' && s[i] <= '9') {
                has_tail_num = true;
            } else if (s[i] != '-' && s[i] != '+') {
                return false;
            }
            ++i;
            while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
                has_tail_num = true;
                ++i;
            }
            if (!has_tail_num)
                return false;
        }
        // skip tail space
        while (i < s.size() && s[i] == ' ') ++i;
        // final result
        return has_front_num && i >= s.size();
    }
};
```
![image.png](https://pic.leetcode-cn.com/c16d6e48a43fcc55a67129112fb151ccc619440e7ac759dc2c097b3b45ad5d8f-image.png)
