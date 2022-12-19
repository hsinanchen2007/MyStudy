```Java
public String gcdOfStrings(String str1, String str2) {
    if (invalid(str1, str2)) {
        return "";
    }
    if (!Objects.equals(str1 + str2, str2 + str1)) {
        return "";
    }
    return str1.substring(0, gcd(str1.length(), str2.length()));
}

/**
 * 检测值的鲁棒性
 */
public boolean invalid(String str1, String str2) {
    return str1 == null || str2 == null || str1.isEmpty() || str2.isEmpty();
}

/**
 * 求解最大公约数
 */
public int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}
```
