### 解题思路
双指针及递归

### 代码

```java
class Solution {
    public void reverseString2(char[] s) {
        int start = 0;
        int end = s.length - 1;
        while (start < end) {
            char temp = s[end];
            s[end] = s[start];
            s[start] = temp;
            ++start;
            --end;
        }
    }

    public void reverseString(char[] s) {
        helper(s, 0, s.length - 1);
    }

    public void helper(char[] s, int start, int end) {
        if (s.length == 0 || start >= end) return;
        char temp = s[end];
        s[end] = s[start];
        s[start] = temp;
        helper(s, ++start, --end);
    }
}
```