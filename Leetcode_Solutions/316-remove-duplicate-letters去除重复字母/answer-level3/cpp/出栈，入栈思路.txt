### 解题思路
1、当遇到的字符比上一个大时，继续入栈；
2、当遇到和上一个字符一样的字符时，直接跳过；
3、当遇到的字符比上一个字符小时，尝试判断后面的s中，是否还存在和上一个字符一致的字符，如果有，则直接把上一个字符出栈，然后入栈当前字符；

### 代码

```cpp
class Solution {
public:
    string removeDuplicateLetters(string s) {
        string str;
        for (int i = 0; i < s.size(); i++) {
            if (str.find(s[i]) != string::npos) {
                continue;
            }
            // 如果此时 入栈的char比上一个小，那么去s的i之后开始找是否有一样的char，如果有一样的char，则就将这个string.back出站,pop_back()
            while (!str.empty() && str.back() > s[i] && s.find(str.back(),i) != string::npos) {
                str.pop_back();
            }
            str.push_back(s[i]);
        }
        return str;
    }
};
```