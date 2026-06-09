### 解题思路
此处撰写解题思路
就是双指针，isalnum(char ), tolower(char )这三个东西的使用。 
### 代码

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        // 这玩意儿一看就知道是双指针啊
        string str;
        for (auto c : s) {
            if (isalnum(c))
                str += tolower(c);
        }
        for (int i = 0; i < str.size() / 2; i++) {
            if (str[i] != str[str.size()-i-1])
                return false;
        }
        return true;

    }

    bool validChar(char c) {
        if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >=97 && c <= 122))
            return true;
        return false;
    }
};
```