## 字符串的最大公因子
1. 先找到str1和str2长度的最大公约数x, 取str1或者str2的长度为x的前缀串，若str1和str2能够使用x拼接而成，则为结果X
2. 先判断str1 + str2 是否和 str2 + str1相等，若不相等，则没有满足要求的X； 若相等，则取二者最大公约数的子串即可（可参考官方解读的第三种方法）

```
class Solution {

    public String gcdOfStrings(String str1, String str2) {
        if (str1 == null || str2 == null) {
            return "";
        }
        int len1 = str1.length(), len2 = str2.length();
        int gcd = gcd(len1, len2);
        String X = str1.substring(0, gcd);
        if (canCat(X, str1) && canCat(X, str2)) {
            return X;
        }
        return "";
        // return gcdOfStrings2(str1, str2);
    }

    // 辗转相除计算最大公约数
    private int gcd(int x, int y) {        
        // 第一次要保证x > y
        if (x < y) {
            int t = y;
            y = x;
            x = t;
        }
        while (x % y != 0) {
            int m = x % y;
            x = y;
            y = m;
        }
        return y;
    }

    // 判断能够拼接
    private boolean canCat(String X, String str) {
        int times = str.length() / X.length();
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < times; i++) {
            builder.append(X);
        }
        return builder.toString().equals(str);
    }
}
```

第二种解法：该方法需要验证有效性，参考官方解读第三条
```
private String gcdOfStrings2(String str1, String str2) {
        if (str1 == null || str2 == null) {
            return "";
        }
        StringBuilder sb1 = new StringBuilder(), sb2 = new StringBuilder();
        sb1.append(str1).append(str2);
        sb2.append(str2).append(str1);
        if (!sb1.toString().equals(sb2.toString())) {
            return "";
        }
        int len1 = str1.length(), len2 = str2.length();
        int gcd = gcd(len1, len2);
        return str1.substring(0, gcd);
    }
```
