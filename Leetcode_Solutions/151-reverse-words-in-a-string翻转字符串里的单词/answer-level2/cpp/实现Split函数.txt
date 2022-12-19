### 解题思路
1、实现Split函数
2、进行反转
3、去除首尾部空格

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        vector<string> vecStr;
        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(' ') + 1);
        int index = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                string str = s.substr(index, i - index);
                if (str != "") {
                    vecStr.push_back(str);
                }
                index = i + 1;
            }
        }
        if (index <= s.size() - 1) {
            vecStr.push_back(s.substr(index));
        }
        reverse(vecStr.begin(), vecStr.end());
        string str = "";
        for (string s : vecStr) {
            str = str + s + " ";
        }
        str.erase(str.find_last_not_of(' ') + 1);
        return str;
    }
};
```