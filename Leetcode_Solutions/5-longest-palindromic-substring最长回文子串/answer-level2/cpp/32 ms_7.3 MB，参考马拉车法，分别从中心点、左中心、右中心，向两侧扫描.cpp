### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
         string newStr;
    for (int i = 0; i < s.length(); ++i) {
        newStr += ("@"+ s[i]);
    }
    newStr += "@";
    int l, m, r, n(0), ln(0), rn(0);
    m = newStr.length() / 2;
    l = m - 1;
    r = m + 1;

    bool m_loop;
    bool l_loop;
    bool r_loop;
    int max_start(0), max_n(1);
    while (1) {
        m_loop = m - n >= 0;
        if (m_loop) {
            if (newStr[m - n] == newStr[m + n]) {
                if (n > max_n) {
                    max_start = m - n;
                    max_n = n;
                }
                n += 1;
            } else {
                m_loop = false;
            }
        }
        l_loop = (l - ln) >= 0 && (l + ln) < newStr.length();
        if (l_loop) {
            if (newStr[l - ln] == newStr[l + ln]) {
                if (ln > max_n) {
                    max_start = l - ln;
                    max_n = ln;
                }

                ln += 1;
            } else {
                l -= 1;
                ln = 0;
            }
        }
        r_loop = (r + rn) < newStr.length();
        if (r_loop) {
            if (newStr[r - rn] == newStr[r + rn]) {
                if (rn > max_n) {
                    max_start = r - rn;
                    max_n = rn;
                }
                rn += 1;
            } else {
                r += 1;
                rn = 0;
            }
        }
        if (!m_loop && !l_loop && !r_loop) {
            break;
        }
    }
    string tmpStr = newStr.substr(max_start, 2 * max_n + 1);
    string::size_type pos(0);
    while((pos = tmpStr.find('@'))!=string::npos){
        tmpStr.replace(pos, 1,"");
    }
        return tmpStr;
    }
};
```