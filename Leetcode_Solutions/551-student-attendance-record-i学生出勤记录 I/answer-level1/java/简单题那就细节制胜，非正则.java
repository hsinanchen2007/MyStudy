# contains 找 LLL

- `A` 直接统计即可
- `L` 要求连续三个，`contains` 偷懒

```java
public boolean checkRecord(String s) {
    if (s.contains("LLL")) return false;
    int a = 0;
    for (char c : s.toCharArray()) {
        if (c == 'A' && ++a == 2) return false; // 直接 ++a 并 判断
    }
    return true;
}
```

# 老老实实遍历

- `li` 初始为 `2`，避免第一个就是 `'L'` 时的 `if (li == i - 1)` 的判断被命中
    - `li` 表示上一个 `'L'` 的索引

```java
public boolean checkRecord(String s) {
    int a = 0, l = 1, li = -2; // li 初始 2，避免第一个就是 L 时的 i - 1 判断
    for (int i = 0; i < s.length(); i++) {
        char c = s.charAt(i);
        if (c == 'A' && ++a == 2) return false; // 不变
        else if (c == 'L') {
            if (li == i - 1) l++;
            else l = 1; // 直接当做第 1 个，故 l 初始也是 1
            if (l == 3) return false;
            li = i;
        }
    }
    return true;
}
```

