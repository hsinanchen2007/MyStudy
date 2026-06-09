- 判断字符长度？省了
- 交换字符的 `char temp` ？省了
```java
public void reverseString(char[] s) {
    int left = 0, right = s.length - 1;
    while (left < right) {
        s[left] ^= s[right];
        s[right] ^= s[left];
        s[left++] ^= s[right--];
    }
}
```
