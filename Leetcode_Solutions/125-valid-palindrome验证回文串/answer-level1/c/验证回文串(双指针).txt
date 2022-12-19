### 解题思路
回文串的验证只需判断第i个字符和第len-i-1个字符是否相同，而且题目只需考虑字母和数字字符，且不考虑字母的大小写。于是我们可以设置首尾各一个指针i,j，再用<ctype.h>自带的函数isalnum(char c)来判断字符c是否为字母或者数字，若是，返回1，否则返回0；tolower(char c)函数将字符c转换为对应的小写。

大体的思路：
while (i < j) {
    s[i]，s[j]均为字母或者数字字符
        不同，返回false;
        相同，移动指针i,j;

    s[i]不为字母或者数字字符
        移动指针i;

    s[j]不为字母或者数字字符
        移动指针j;
}
循环结束，该字符串为回文串，返回true

### 代码

```c
bool isPalindrome(char * s)
{
    int len = strlen(s);
    int i = 0, j = len-1;
    
    while (i < j) {
        if (isalnum(s[i]) && isalnum(s[j])) {
            if (tolower(s[i]) != tolower(s[j]))
                return false;
            if (tolower(s[i]) == tolower(s[j]))
                ++i,--j;
        }
        if (!isalnum(s[i]))
            ++i;
        if (!isalnum(s[j]))
            --j;
    }
    return true;
}
```