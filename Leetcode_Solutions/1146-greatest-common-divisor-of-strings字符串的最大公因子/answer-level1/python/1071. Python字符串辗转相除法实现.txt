### 解题思路
对于求最大公约“串”我们很容易想到最大公约数的辗转相除法，思想都是相通的，先来复习一下数字的辗转相除法：`gcd(a, b) = b if a % b == 0 else gcd(b, a % b)`，就算没接触过python的朋友应该也能看出个意思来，当然不要忘了还有个前提是**a >= b**。将这个思路改成字符串也很容易，但是需要注意的是，**最好先确定是否存在这样的最大子串**，原因有如下两点：
（1）可以减少不必要的运算
（2）我们实现字符串的辗转相除法实际上是数字辗转相除法的一种细化，为什么说是细化，因为对于数字a, b来说，a是由a个1组成，b是由b个1组成，那么这些1没有不同，换句话说，如果a > b，那么就可以说a中至少包括一个b，但对于字符串来说就不是这样，因为每个字符还需要相同，所以如果不事先判断是否有解的情况下，我们的程序很容易陷入死循环，拿样例来说就是'leet'和'code'，`'leet' % 'code' = leet`，那么根据步骤，下一步迭代就是`'code' % 'leet' = 'code'`，即陷入死循环，当然我们可以通过后续的处理进一步判断是否存在无解的情况，但是这样程序就会变得复杂，还不如在最开始就进行判断。

### 代码

```python
class Solution(object):
    def gcdOfStrings(self, str1, str2):
        """
        :type str1: str
        :type str2: str
        :rtype: str
        """
        len_1 = len(str1)
        len_2 = len(str2)
        if len_1 == 0 or len_2 == 0 or str1 + str2 != str2 + str1:
            return ''
        if len_1 < len_2:
            temp = str1
            str1 = str2
            str2 = temp
        def str_mod(s1, s2):
            ind = 0
            len_2 = len(s2)
            while s1[ind: ind + len_2] == s2:
                ind += len_2
            return s1[ind:]
        res = str_mod(str1, str2)
        while res != '':
            str1 = str2
            str2 = res
            res = str_mod(str1, str2)
        return str2
```