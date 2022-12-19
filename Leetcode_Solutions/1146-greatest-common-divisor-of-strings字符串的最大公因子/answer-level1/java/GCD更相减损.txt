### 解题思路
经过在草稿纸上的几次演示之后，很容易发现这个原理跟平常两个整数的GCD是很类似的。由于String类型不能够真正地进行除法，但减法还是能够很方便地利用子串进行模拟，所以我更倾向于利用“更相减损”的方法来进行模拟。
大概地推导一次，更相减损的原理吧：
- 首先我们的目的是要将原问题简化，简化到我们能够一眼确定答案，如何做到呢？数字越小，从人的角度看越容易判断公因数，而两数中有一个为0，则公因数就是另一个数(gcd的定义)。
- 假设两个数a和b，设r为a和b的最大公因数，那么有a=xr, b=yr。
- 我们令a为更加大的一方，则a=b+m，将ab和r的关系带入有xr=yr+m, (x-y)r=m!
- 所以可以发现，差值m也是r的倍数，所以求解a和b的最大公约数等价于求(a-b)和b的最大公约数。

辗转相除的原理也类似，只不过辗转相除更优，它每次减少的量比更相减损更多。
再来看回这道题，由题意可知，我们可以把两个字符串的相差的部分子串抽象为上边的m值，接着迎刃而解！

### 代码

```java
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        if (str1.length() == 0) return str2;
        else if (str2.length() == 0) return str1;
        if (str1.length() == str2.length()) {
            if (str1.equals(str2)) return str1;
            else return "";
        } else if (str1.length() < str2.length()) {
            String tmp = str1;
            str1 = str2;    str2 = tmp;
        }
        return gcdOfStrings(str1.substring(str2.length()), str2);
    }
}
```