### 解题思路
对于s[i...j]字符串，若要删除左边字符，则只需再递归看s[i+1...j]是否为回文；
同理，若要删除右边字符，则只需再递归看s[i...j-1]是否回文；
注意只能删一个字符，所以递归函数用delCnt记录删除次数。
特殊情况，若s[i]==s[j]，则不需要删除，只需向内s[i+1...j-1]递归检查。

![图片.png](https://pic.leetcode-cn.com/272c05646cc317a3c54bc9598cf35d0790c7a8e832f5510fae151961ff141492-%E5%9B%BE%E7%89%87.png)

### 代码

```cpp
class Solution {
public:
    // 表示删除delCnt个字符得到的字符串s[i...j]是否是回文
    bool validPalindrome(string& s, int i, int j, int delCnt) {
        if (delCnt > 1) {  // 删除字符数多于1，裁剪
            return false;
        }

        if (i >= j) {  // 已遍历完字符串，OK
            return true;
        }

        if (validPalindrome(s, i + 1, j, delCnt + 1)) {  // 递归检查删除左边的字符后，是否回文
            return true;
        }

        if (validPalindrome(s, i, j - 1, delCnt + 1)) {  // 递归检查删除右边的字符后，是否回文
            return true;
        }

        if (s[i] == s[j] && validPalindrome(s, i + 1, j - 1, delCnt)) {  // 如果两端相等，则检查不删除的情况，向内递归检查
            return true;
        }

        return false;
    }

    bool validPalindrome(string s) {
        return validPalindrome(s, 0, s.size() - 1, 0);
    }
};
```