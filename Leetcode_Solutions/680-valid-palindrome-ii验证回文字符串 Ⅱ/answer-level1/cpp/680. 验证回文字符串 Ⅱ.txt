### 解题思路
双指针。

如果字符串本身是回文串，则无需判断直接返回true（注意题述：“最多”删除一个字符）。

字符串本身不是回文串，从两头向中间查找不相等的字符，找到后分别删除两个字符，并判断删除后**中间的子串**是否回文串，用同样的方法查找子串是否含有对应位置不相等的字符，若存在则返回false，否则返回true。

### 代码

```cpp
class Solution {
public:
    bool validPalindrome(string s) {
        if (isPalindrome(s))
            return true;
        //双指针从两头往中间找不相同的字符
        int i = 0;
        int j = s.length() - 1;
        while (i < j)
        {
            if (s[i] != s[j]) {
                if (isPalindrome(s.substr(i, j - i)) || isPalindrome(s.substr(i + 1, j - i)))
                    return true;
                return false;
            }
            i++;
            j--;
        }
        return false;
    }

    //判断是否回文串
    bool isPalindrome(string s) {
        for (int i = 0; i < s.length() / 2; i++) {
            if (s[i] != s[s.length() - 1 - i])
                return false;
        }
        return true;
    }

};
```