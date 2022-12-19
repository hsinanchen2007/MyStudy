### 解题思路
思路就是先对字符串做处理，只留下字母和数字，大写字母转为小写。然后可以用下边代码里的对称比较是否相等，或者可以用双指针分别从首尾两端，边逼近中心边比较是否相等。

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        if (s == " ") return true;
        vector<char> r;
        for (int i = 0; i < s.length(); i++) {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
                r.push_back(s[i]);
            }
            if (s[i] >= 'A' && s[i] <= 'Z') {
                r.push_back(s[i] - 'A' + 'a');
            }
        }
        for (int i = 0; i < r.size()/2; i++) {
            if (r[i] != r[r.size() - i - 1]) return false;
        }
        return true;
    }
};
```