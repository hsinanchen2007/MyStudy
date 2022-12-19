### 解题思路
我就是个傻子菜鸡

### 代码

```java
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        if (!(str1 + str2).equals(str2 + str1)) return "";
        // 截取最大公约数长度的子串
        return str1.substring(0, gcd(str1.length(), str2.length()));
    }
    // 辗转相除法求最大公约数
    public int gcd(int a, int b){
        return b == 0 ? a : gcd(b, a%b);
    }
}
```