```python []
class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = [*filter(str.isalnum, s.lower())]
        return s == s[::-1]
```
```cpp []
class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for(auto c: s) if(isalnum(c)) str += tolower(c);
        for(int i=0, m=str.size(); i<m/2; ++i)
            if(str[i] != str[m-1-i]) return false;
        return true;
    }
};
```
- 首先利用`isalnum`函数排除非字母数字，`lower/tolower`将所有字母转为小写
- 然后镜像对比处理后的字符串
