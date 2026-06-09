### 解题思路
因为s1和s2存在公因子可以推导出s1+s2=s2+s1,所以s1+s2!=s2+s1可以推导出s1和s2不存在公因子，之后用辗转相除法即可解决。

### 代码

```java
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        if(!(str1+str2).equals(str2+str1)){
            return"";
        }
        return str1.substring(0,gcd(str1.length(),str2.length()));
    }
    private int gcd(int a , int b){
        return b==0 ? a : gcd(b , a%b);
    }
}
```