### 解题思路
辗转相除法是递归算法，一句话概括这个算法就是：两个整数的最大公约数，等于其中较小的数 和两数相除余数 的最大公约数。
比如 10 和 25，25 除以 10 商 2 余 5，那么 10 和 25 的最大公约数，等同于 10 和 5 的最大公约数。

### 代码

```java
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        if(!(str1 + str2).equals(str2 + str1)) return "";
        int maxCommonDividor = gcd(str1.length(),str2.length());
        return str1.substring(0,maxCommonDividor);
    }

    public int gcd(int a, int b){
        return a % b == 0 ? b : gcd(b , a % b);
    }
}
```