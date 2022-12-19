### 解题思路
因为求最大的因子 那么首先就应该想到gcd算法，然后之间截取字符串就ok了

### 代码

```java
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        if(!(str1 + str2).equals(str2 + str1)){
            return "";
        }
        int m = gcd(str1.length(),str2.length());
        return str1.substring(0,m);

    }
       // 辗转相除法求最大公约数
    private int gcd(int a, int b) {
        return (a % b == 0) ? b : gcd(b, a % b);
    }
}
```