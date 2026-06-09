### 解题思路
首先，需要知道一个性质：如果 str1 和 str2 拼接后等于 str2和 str1 拼接起来的字符串，那么一定存在符合条件的最大公约数 X。
之后用辗转相除，确定了是否有解后，观察可知，可以用字符串的长度来进行辗转相除

### 代码

```java
class Solution {
    public String gcdOfStrings(String str1, String str2)    {
        if(!(str1+str2).equals(str2+str1))
        return "";
        return str1.substring(0,gcd(str1.length(),str2.length()));
    }
    //辗转相除求最大公约数
    private int gcd(int a,int b)
    {
        //除数作为新的被除数，商作为新的除数，直到商为0时，输出对应的除数
        return b==0 ? a: gcd(b,a%b);
    }
}
```