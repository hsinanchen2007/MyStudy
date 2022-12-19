### 解题思路
用两个指针从字符串的两端开始对比。当两头相等的时候，指针相对移动一位，当两头不想等的时候，尝试比较删除左边或者右边之后，剩下的字符串是否为回文字符串。这里我将这个判断函数提出来写了一个辅助函数isPalindrome。将左边和右边这两种结果或运算之后就可以直接return了。

### 代码

```c
bool isPalindrome(char *str, int i, int j) {
    while (i < j) {
        if (str[i++] != str[j--]) {
            return false;
        }
    }
    return true;
}

bool validPalindrome(char * s){
    int len = strlen(s);
    int i = 0, j = len - 1;
    while (i < j) {
        if (s[i] != s[j]) {
            return isPalindrome(s, i, j - 1) || isPalindrome(s, i + 1, j);
        } else {
            i++;
            j--;
        }
    }
    return true;
}
```