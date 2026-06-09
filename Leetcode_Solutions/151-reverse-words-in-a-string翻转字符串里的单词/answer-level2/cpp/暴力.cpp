### 解题思路
暴力
### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        int len = s.size();
        string ans = "";
        for (int i=0; i<len; i++) {
            string temp = "";
            while (s[i] != ' ' && i < len) {
                temp += s[i];
                i++;
            }
            if (temp != "") {
                ans = temp + " " + ans;
            }
        }
        len = ans.size() - 1;
        ans = ans.substr(0, len);
        return ans;
    }
};
```