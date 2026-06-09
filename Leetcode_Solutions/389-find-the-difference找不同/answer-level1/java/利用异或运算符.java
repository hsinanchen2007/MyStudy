### 解题思路
一个数**与同一个数异或两次**等于没有异或
而且与异或的顺序不影响

### 代码

```java
class Solution {
    public char findTheDifference(String s, String t) {
        // 初始值为 t 最后的字符
        int a = t.charAt(t.length() - 1);
        
        int len = s.length();
        
        for (int i = 0; i < len; i++) {
            // 用a和 s t(除去最后一个)中的字符异或运算
            a = a^s.charAt(i)^t.charAt(i);
        }
        return (char)a;
    }
}
```