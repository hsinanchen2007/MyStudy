### 解题思路
记一笔 c++的几个内置函数
1. islower(char c) 是否为小写字母
2. isuppper(char c) 是否为大写字母
3. isdigit(char c) 是否为数字
4. isalpha(char c) 是否为字母
5. isalnum(char c) 是否为字母或者数字 
6. toupper(char c) 字母小转大
7. tolower(char c) 字母大转小

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        string tmp;
        for (auto c : s) {
            if (islower(c) || isdigit(c))  tmp += c;
            else if (isupper(c)) tmp += (c + 32);
        }
        int i = 0, j = tmp.size() - 1;
        while (i < j) {
            if (tmp[i] != tmp[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
```