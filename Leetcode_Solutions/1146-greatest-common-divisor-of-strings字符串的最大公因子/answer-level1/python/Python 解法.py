### 解题思路
看了精选题解里王德福的解法，总体思路上虽然和官方的优化枚举的一样，但是还是感觉王德福的在判断是否有解的情况，要更优一些。官方是先假设有解，再去判断，代码量和效率应该是要逊色一些的。

所以写下一个参照了王德福的思路写的python版本

[王德福的题解](https://leetcode-cn.com/problems/greatest-common-divisor-of-strings/solution/1071-zi-fu-chuan-de-zui-da-gong-yin-zi-by-wonderfu/)里有一句话，“因为如果能循环以它的约数为长度的字符串，自然也能够循环以它为长度的字符串，所以这个理论长度就是我们要找的最优解”。

直观上是有点不太好理解的，所以拿个例子来说明一下，比如一个长度为8，一个长度为4，那假设最优解是2，不是4，对于长度为8的可以理解成，要有4个这样的前缀，长度为4的要有2个这样的前缀。然后这时候4个这样的前缀，和2个这样的前缀，实际上又可以有共同的约数2来合并，而且不合并的话实际上就不是最优的长度。无论两个数有多少约数的情况都可以这样类推合并。因此最优解就是在最大公约数，当然，前提是要确定是有解的。

### 代码

```python3
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if (str1 + str2) != (str2 + str1):
            return ""
        return str1[ :math.gcd(len(str1), len(str2))]
        
```



