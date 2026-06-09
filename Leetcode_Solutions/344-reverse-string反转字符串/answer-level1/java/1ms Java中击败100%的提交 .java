### 解题思路
这题就是怎么快怎么来了

### 代码

```java
class Solution {
   public void reverseString(char[] s) {
        char c;
        int l = s.length;
        int halfL = l / 2;
        int l2 = l - 1;
        int endIndex;
        for (int i = 0; i < halfL; i++) {
            endIndex = l2 - i;
            c = s[endIndex];
            s[endIndex] = s[i];
            s[i] = c;
        }
    }
}
```