### 解题思路
顺着题目干就完事了.

### 代码

```java
class Solution {
     public String compressString(String S) {
        int len = S.length();
        StringBuilder sb = new StringBuilder();
        int t = 1;
        char c1 = ' ';
        char c2 = ' ';
        for (int i = 0; i < len - 1; i++) {
            c1 = S.charAt(i);
            c2 = S.charAt(i + 1);
            if (c1 != c2) {
                sb.append(c1);
                sb.append(t);
                t = 1;
            } else {
                t++;
            }
        }
        sb.append(c2);
        sb.append(t);
        return sb.length()<len?sb.toString():S;
    }
}
```