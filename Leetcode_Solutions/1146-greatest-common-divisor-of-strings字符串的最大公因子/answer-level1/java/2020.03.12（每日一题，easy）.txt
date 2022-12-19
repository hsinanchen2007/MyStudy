### 解题思路
本题考查字符串的**最大公因子**

字符串 A 和 B 拼接起来和反向拼接一样则满足S=T+T+T+...

这里使用gcd函数，巧妙将公因子筛选出来

传入两个字符串的长度a和b，依次将短的长度b和0比较，若不为0，则将长度a除以b直到整除，即达到最大公因子的寻找

### 代码

```java
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        int n1 = str1.length();
        int n2 = str2.length();
        
        if(!(str1 + str2).equals(str2 + str1)){//字符串相反拼接是否一致
            return "";
        }        
        return str1.substring(0, gcd(n1, n2));//输出最大公因子
    }
    
    private int gcd(int a, int b){//gcd函数
        return b == 0 ? a : gcd(b, a % b);//很妙的算法
    }    
}
```