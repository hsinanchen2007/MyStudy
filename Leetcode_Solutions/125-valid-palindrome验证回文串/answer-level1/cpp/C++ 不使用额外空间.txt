### 解题思路
首先读懂题意，不是字母或数字都忽略；
那么就从两端开始找字母或数字的字符，如果不相等就返回false，走到最后就返回true

![图片.png](https://pic.leetcode-cn.com/e89136dd209248dbce071f3e49b1a98a194f75b4818b2df5ebdc0416c7f3f9f4-%E5%9B%BE%E7%89%87.png)


### 代码

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) {
            return true;
        }
        
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            while (i < j && !isalnum(s[i])) {++i;}   // 从左边开始找一个字母或者数字
            while (i < j && !isalnum(s[j])) {--j;}   // 从右边开始找一个字母或者数字
            if (tolower(s[i++]) != tolower(s[j--])) {
                return false;
            }
        }
        return true;
    }
};
```