### 法一
先求出leng1 与length2的最大公约数，然后判断即可。

### 代码

```java
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        int n = getGCD(str1.length(), str2.length());
        if (1 == n) {
            return str1.charAt(0) == str2.charAt(0) ? str1.substring(0, 1) : "";
        }
        String t = str1.substring(0, n);
        return isGCD(str1, t) && isGCD(str2, t) ? t : "";
    }

    private boolean isGCD(String str, String t) {
        int start = 0;
        while (str.indexOf(t, start) >= 0) {
            start += t.length();
        }

        return start == str.length();
    }

    private int getGCD(int a, int b) {
        if (a < b) {//交换
            a = a + b;
            b = a - b;
            a = a - b;
        }
        int r = 1;
        while (0 != r) {
            r = a % b;
            a = b;
            b = r;
        }

        return a;
    }
}
```

###法二
其实也是法一的思路，不过这里有点优化：
如果它们有公因子 abc，那么 str1 就是m个 abc 的重复，str2 是 n 个 abc 的重复，连起来就是 m+n 个 abc，好像m+n 个 abc 跟 n+m 个 abc 是一样的。所以如果 str1 + str2 === str2 + str1 就意味着有解。
我们也很容易想到 str1 + str2 !== str2 + str1 也是无解的充要条件。
当确定有解的情况下，最优解是长度为 gcd(str1.length, str2.length) 的字符串。这个理论最优长度是不是每次都能达到呢？是的。因为如果能循环以它的约数为长度的字符串，自然也能够循环以它为长度的字符串，所以这个理论长度就是我们要找的最优解。

```java
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        if (!(str1 + str2).equals(str2 + str1)) {
            return "";
        }
        int n = getGCD(str1.length(), str2.length());
        return str1.substring(0, n);
    }

    private int getGCD(int a, int b) {
        if (a < b) {//交换
            a = a + b;
            b = a - b;
            a = a - b;
        }
        int r = 1;
        while (0 != r) {
            r = a % b;
            a = b;
            b = r;
        }

        return a;
    }
}
```
