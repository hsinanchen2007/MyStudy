![image.png](https://pic.leetcode-cn.com/8e01e5ebd36e0f2ea70dd43ed253ef39fc13a31abfc08ce77392b824289c64d0-image.png)
```java
class Solution {
   public void reverseString(char[] s) {
        int len = s.length;
        int halfLen = s.length / 2;
        for (int i = 0; i < halfLen; i++) {
            char temp = s[i];
            s[i] = s[s.length - i -1];
            s[s.length - i -1] = temp;
        }
    }
}
```