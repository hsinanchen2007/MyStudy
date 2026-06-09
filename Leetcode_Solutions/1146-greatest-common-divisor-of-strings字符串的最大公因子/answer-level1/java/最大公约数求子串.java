### 解题思路
# 关键点：两个字符串有最大公因子串条件是 (str1 + str2).equals(str2 + str1)
**若有最大公因子串，则子串长度为两子串长度的最大公因数**

### 代码

```java
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        if(!(str1 + str2).equals(str2 + str1)){
            return "";
        }
        //现在一定有最长子串，最长子串的长度为str1和str2长度的最大公约数
        return str1.substring(0, gcd(str1.length(), str2.length()));

    }

    public int gcd(int x, int y){
        if(x < y){
            if(x == 0){
                return y;
            }else{
                return gcd(y % x, x);
            }
        }else{
            if(y == 0){
                return x;
            }else{
                return gcd(y, x % y);
            }
        }
    }
}
```