### 解题思路
类似gcd算法，使用递归可以求解。

![image.png](https://pic.leetcode-cn.com/9a8a1adbb9c1409f11c9ecf0540494b0f1a05448411b7829ae43b77c314ac0a2-image.png)

### 代码

```java
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        if (str1.length() < str2.length()) {
            String tmp = str1;
            str1 = str2;
            str2 = tmp;
        }
        String prefix = str1.substring(0, str2.length());
        if (!prefix.equals(str2)) return "";
        else if (str1.length() == str2.length()) return str1;
        else return gcdOfStrings(str2, str1.substring(str2.length()));
    }
}
```