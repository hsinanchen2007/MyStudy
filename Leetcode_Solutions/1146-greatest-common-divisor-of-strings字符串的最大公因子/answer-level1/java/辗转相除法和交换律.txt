### 解题思路
1. 如果两个字符串有公因子，则满足交换律，反之亦然（这个反之亦然是本题的关键，等待大神证明。。）
2. 利用“辗转相除法”来求最大公因子的字符串长度（“辗转相除法”依据的是（A，B）与（B，A%B）具有同样的公因子）

### 代码

```java
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        if(!(str1 + str2).equals(str2 + str1)) {
            return "";
        }
        return str1.substring(0, getGCD(str1.length(), str2.length()));
    }

    public int getGCD(int a, int b) {
        return a % b == 0 ? b : getGCD(b, a % b);
    }
}
```