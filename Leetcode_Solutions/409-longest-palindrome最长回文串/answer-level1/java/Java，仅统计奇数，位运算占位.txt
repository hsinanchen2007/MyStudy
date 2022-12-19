## 仅统计奇数

- 总长度 - 奇数个数 + 奇数取一作为回文中心

```java
public int longestPalindrome(String s) {
    int[] freq = new int[58]; // from A to z
    for (char c : s.toCharArray()) freq[c - 'A']++;
    int odd = 0;
    for (int f : freq) odd += f & 1; // if (f % 2 == 1) odd++;
    return s.length() - odd + (odd > 0 ? 1 : 0);
}
```


## 位运算占位

- 位运算作为储物柜，等待下一个相同字符
- 储物柜里剩余的，就是奇数个数

```java
public int longestPalindrome(String s) {
    int odd = 0;
    long freq = 0b0L; // 64 bits > 58 chars(from A to z)
    for (char c : s.toCharArray()) {
        long ori = freq;
        freq ^= 1L << (c - 'A'); // 异或占位，1L 为 long，而非 1 的 int
        if (freq > ori) odd++; // 统计后增加，说明多了一个等待者
        else odd--; // 统计后减少，说明来了相同字符凑成偶数，故奇数统计 - 1
    }
    return s.length() - odd + (odd > 0 ? 1 : 0);
}
```
