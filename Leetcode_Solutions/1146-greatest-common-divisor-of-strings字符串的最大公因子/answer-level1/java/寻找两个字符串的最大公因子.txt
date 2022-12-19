### 解题思路
以两个字符串的长度为参数，寻找他们的最大公约数。
将最大公约数作为substring的终端长度，从0开始搜索。

### 代码

```java
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        if(!(str1+str2).equals(str2+str1))
        {
            return "";
        }
        return str1.substring(0,gcd(str1.length(),str2.length()));
    }
    private int gcd(int a,int b)
    {
        int c;
        if(b == 0)
            return a;
        else
            c = gcd(b,a%b);
            return c;

        //return b == 0? a: gcd(b,a%b);
    }
}
```