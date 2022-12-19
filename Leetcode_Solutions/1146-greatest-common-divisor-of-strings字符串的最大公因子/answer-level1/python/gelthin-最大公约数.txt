### 解题思路
计算最大公约数 gcd(a,b) = gcd(b, a%b)  # 这里要限制 a,b >0

可以证明： 如果存在一个数 k 使得 str1[:k] 能够整除 str1 和 str2, 那么有 k 整除 n1, n2, 可以推出 k 整除 gcd(n1,n2)
那么必然有 l = gcd(n1,n2) 满足 str1[:l] 能够整除 str1 和 str2。

想象一下铺地板的过程。 k 能够恰好铺满，那么 l 也必然能够铺好。

官方题解还提供了一些巧妙的做法 比如说： return a+b == b+a



### 代码

```python3
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        n1, n2 = len(str1), len(str2)
        a, b = n1, n2
        while a%b != 0:
            a, b = b, a%b
        # gcd 为 b    
        # 似乎可以证明，如果存在某个 比 b 小的数能够实现除尽，那么 必然 b 也能除尽。
        # 因此，如果 b 除不尽，那么就无解了。
        if str1[:b] != str2[:b]:
            return ""
        if str1[:b]*(n1//b) == str1 and str2[:b]*(n2//b) == str2:
            return str1[:b]
        else:
            return ""

```