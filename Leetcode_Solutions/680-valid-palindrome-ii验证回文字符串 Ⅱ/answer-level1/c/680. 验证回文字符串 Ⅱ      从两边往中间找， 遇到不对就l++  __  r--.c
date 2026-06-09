### 解题思路

给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。

示例 1:

输入: "aba"
输出: True

### 代码

```c
bool Palindrome(char *s, int l, int r){
    while (l<r) {
        if (s[l++] != s[r--])
            return false;
    }
    return true;
}

bool validPalindrome(char * s){
    int  l = 0, r = strlen(s) - 1;

    while (l<r) {
        if (s[l] == s[r]) {
            l++,r--;
        } else
            return Palindrome(s, l + 1, r) || Palindrome(s, l, r - 1);
    }
    return true;
}
```