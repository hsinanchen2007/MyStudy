- `l` , `r` 左右指针
- 初始 `-1` 与 `len`，利用 `while` 条件时同一行处理
- 位运算交换两字符
- 别忘了总得判断 `l < r`
```java
public String reverseOnlyLetters(String S) {
    char[] arr = S.toCharArray();
    int len = arr.length, l = -1, r = len;
    if (len < 2) return S;
    while (l++ < r--) {
        while (l < r && !valid(arr[l])) l++;
        while (l < r && !valid(arr[r])) r--;
        if (l < r) {
            arr[l] ^= arr[r];
            arr[r] ^= arr[l];
            arr[l] ^= arr[r];
        }
    }
    return new String(arr);
}

private boolean valid(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
```
