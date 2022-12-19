![image.png](https://pic.leetcode-cn.com/0e617309d8cfe7ce3ba140e5d1f9788fb6632c65c1fc69a1bad463c43cf72f21-image.png)

### 解题思路
双指针解决，前后调换字母

### 代码

```java
class Solution {
    public String reverseOnlyLetters(String S) {
        char[] chars = S.toCharArray();
        int head = 0, last = chars.length - 1;

        while (head < last) {
            if (checkChar(chars[head])) {
                while (head < last) {
                    if (checkChar(chars[last])) {
                        char c = chars[last];
                        chars[last] = chars[head];
                        chars[head] = c;
                        last--;
                        break;
                    }
                    last--;
                }
            }
            head++;
        }

        return new String(chars);
    }

    private boolean checkChar(char c) {
        return (c >= 65 && c <= 90) || c >= 97;
    }
}
```