```
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        //如果str1+str2与str2+str1不等，说明不包含公共的子串
        if (!(str1 + str2).equals(str2 + str1))
            return "";
        return str1.substring(0, gcd(str1.length(), str2.length()));
    }
    //辗转相除法
    public int gcd(int a, int b) {
        return b == 0? a: gcd(b, a % b);
    }
}
```
