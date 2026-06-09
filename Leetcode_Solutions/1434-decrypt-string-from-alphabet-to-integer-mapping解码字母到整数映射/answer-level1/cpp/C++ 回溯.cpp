### 解题思路
当前字符要么独立解码，要么和后面2个字符组合解码；
搜索所有情况，满足条件就返回。

![image.png](https://pic.leetcode-cn.com/bab8e1281f41b56594d1e4c8518bad3d621dd3592526e41aa744c7de4c40cb0c-image.png)

### 代码

```cpp
class Solution {
public:
    string ans;

    bool backtrace(string& s, int i, string& result) {
        if (i == s.size()) {
            ans = result;
            return true;
        }
        if ('1' <= s[i] && s[i] <= '9') {
            result.push_back('a' + s[i] - '1');
            int check = backtrace(s, i + 1, result);
            result.pop_back();
            if (check) {
                return true;
            }
        }
        if (i < s.size() - 2 && s[i + 2] == '#') {
            string subs = s.substr(i, 2);
            int num = stoi(subs);
            if (10 <= num && num <= 26) {
                result.push_back('a' + num - 1);
                int check = backtrace(s, i + 3, result);
                result.pop_back();
                if (check) {
                    return true;
                }
            }
        }
        return false;
    }
    
    string freqAlphabets(string s) {
        string result;
        backtrace(s, 0, result);
        return ans;
    }
};
```