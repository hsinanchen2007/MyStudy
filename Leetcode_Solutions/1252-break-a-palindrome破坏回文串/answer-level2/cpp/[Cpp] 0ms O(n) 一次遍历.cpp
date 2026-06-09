### 解题思路
首先遍历前半部分，如果哪个字符不是'a'直接改成'a'必是最小
如果前半部分全是'a'，那么后半部分也一样，此时更改最后一个字符，可以使字典序最小

### 代码

```cpp
class Solution {
public:
    string breakPalindrome(string palindrome) {
        if (palindrome.size() < 2) return "";
        int n = palindrome.size();
        for (int i = 0; i < n / 2; i++) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome[n - 1] = 'b';
        return palindrome;
    }
};
```