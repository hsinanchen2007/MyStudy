### 解题思路
把字符串拆了，然后逆序拼接

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s)
    {
        vector<string> strvec;
        string result;
        string str;
        stringstream sstream;
        sstream << s;
        while (getline(sstream, str, ' ')) {
            if (!str.empty()) {
                strvec.push_back(str);
            }
        }

        reverse(strvec.begin(), strvec.end());

        for (auto tmps : strvec) {
            result += tmps;
            result += " ";
        }

        if (!result.empty()) {
            result.pop_back();
        }


        return result;
    }
};
```