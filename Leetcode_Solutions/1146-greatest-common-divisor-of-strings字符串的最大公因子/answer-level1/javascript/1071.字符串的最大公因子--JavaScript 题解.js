通过欧几里得算法（辗转相除法）求解
如果 字符串 str1 和 str2 有最大公因子 ab ，那么意味着 str1 = n 个 ab  &&  str2 = m 个 ab
str1 + str2 = (m + n) 个 ab = str2 + str1, 这是有解的前提
接下来就是算两个字符串长度的最大公因子

假设有两个整数为a和b，他们的公约数可以表示为gcd(a,b)。
如果 gcd(a,b) = c,则 a = mc 和 b = nc 
a % b = r 可以表示为 r = a - k*b
因为 c 为 a 和 b 的最大公约数，所以 r = mc - k*nc = (m-nk)c, 所以 c 也是 r 的最大公约数
所以gcd(a,b) = gcd(b,r)，相当于把较大的一个整数用一个较小的余数替换了，这样不断地迭代，直到余数为0找到最大公约数

假设两个整数为6和4：
6, 4 -> 4, 2 -> 2, 0 -> 公约数为 2

```
var gcdOfStrings = function (str1, str2) {
    if ((str1 + str2) !== (str2 + str1)) return ''
    return str1.substring(0, gcd(str1.length, str2.length))
};
function gcd(a, b) {
    return b === 0 ? a : gcd(b, a % b)
}
```
