### 解题思路
1、根据题目，如果存在最大公约数，那么str1+str2 = str2+str1
2、根据辗转相除法求得两个字符串长度的最大公约数
3、截取字符串

### 代码

```java
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        if(!(str1+str2).equals(str2+str1)){
            return "";
        }
        return str1.substring(0,gcd(str1.length(),str2.length()));
    }
    private int gcd(int a,int b){
        if(a == 0){
            return b;
        }
        if(b == 0){
            return a;
        }
        return gcd(b,a%b);
    }
}
```