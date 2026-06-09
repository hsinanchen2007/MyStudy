### 解题思路
输入的两个字符串只有当`(str1+str2).equals(str2+str1)`时才能有解。
找最大公约数可以看成对两个字符串的长度取最大公约数，然后从0截取最大公约数长度的串
返回即可
### 代码

```java
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        if(!(str1+str2).equals(str2+str1))
            return "";
        int p = str1.length();
        int q = str2.length();
        int result = gcd(p,q);
        return str1.substring(0,result);

    }

    public int gcd(int p, int q)
    {
        return q == 0? p:(gcd(q,p%q));
    }
}
```