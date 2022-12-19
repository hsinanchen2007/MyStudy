```java
public boolean isPalindrome(String s) {
    int left = 0;
    int right = s.length() - 1;
    while (left < right) {
// left和right可能是合法字符，也可能left和right重合（不确定合不合法），但不影响结果，因为同个字符必定相等
        while (left < right && !isValid(s.charAt(left))) ++left;
        while (left < right && !isValid(s.charAt(right))) --right;
        if (!isEquals(s.charAt(left), s.charAt(right))) {
            return false;
        }
        ++left;
        --right;
    }
    return true;
}
private boolean isValid(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}
private boolean isEquals(char a, char b) {
    if ((a >= '0' && a <= '9') || (b >= '0' && b <= '9')) return a == b;
    if (a >= 'A' && a <= 'Z') a += 'a' - 'A';
    if (b >= 'A' && b <= 'Z') b += 'a' - 'A';
    return a == b;
}
```