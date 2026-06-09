# 思路
首先如果字符串长度为**奇数**，则字符串**中间**的那个字符无论怎么改，字符串都是回文串。
如：`aba`，`b`字符无论怎么改，字符串都还是**回文串**。

回文串**前半段**和**后半段**是**相互对应**的，因此只要遍历一半就好了。

首先遍历前半段，遇到不为`a`的字符就直接将其替换成`a`，然后直接return结果。
如果前半段都是`a`，则说明后半段也都是`a`，说明字符串要么类似`aabaa`，要么类似`aaaaaa`。
直接将最后1个字符改成`b`就好了。

# 代码
```java
class Solution {
    public String breakPalindrome(String palindrome) {
        int len = palindrome.length(), half = (len - 2) >> 1;
        if (len < 2) return "";
        char[] ch_arr = palindrome.toCharArray();
        for (int i = 0; i <= half; ++i)
            if (ch_arr[i] > 'a') {
                ch_arr[i] = 'a';
                return String.valueOf(ch_arr);
            }
        ch_arr[len - 1] = 'b';
        return String.valueOf(ch_arr);
    }
}
```
