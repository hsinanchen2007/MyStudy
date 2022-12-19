![image.png](https://pic.leetcode-cn.com/16cb8a2931f719455b7241cd5ef417dc910962f2c549060438806c52cb9f4f80-image.png)
官方题解的seen是个set，记录一个长为L的子串是否已经出现过。
替换为dict之后，记录这个子串出现的位置（结束位置）。
若重复出现，则valid()函数（官方题解的search()）返回一个tuple，分别是两次出现的位置：pos1和pos2。

这样有什么好处？可以避免一些重复计算。
例如一个输入为"aaaaaaaaaaaaaaaa"（长为15），正常的二分做法：
1、left = 0, right = 16, L=8，发现S[0:8] == S[1:9]，满足条件，退出。
2、left = 8, right = 16, L=12，计算S[0:12]的时候，重复计算了S[0:8]。之后发现S[1:13] == S[0:12]，退出。
3、(left, right, L) = (12, 16, 14)，计算S[0:14]的时候，S[0:12]又要重复算一遍。

改进之后，第一次发现S[0:8] == S[1:9]，返回（8,9），表示：以位置8结束，长为L的子串==以位置9结束，长为L的子串。
然后在二分的循环中，先不更新left。
而是两个串顺序向后扫描。
若S[9] == S[10]，则表示：以位置9结束，长为L+1的子串 == 以位置10结束，长为L+1的子串；
若S[10] == S[11]，则表示：以位置10结束，长为L+2的子串 == 以位置11结束，长为L+2的子串；
……
直到两个字符不相等。
然后把当前扫到的长度更新给left，再进入下一次二分。

改进之后，在极端情况下（例如上述全同字符串），退化为O(n)复杂度。
评测用时由1036ms（100%）缩短到了804ms（100%），所以仿佛还是有点用的。

```
class Solution(object):
    def longestDupSubstring(self, S):
        """
        :type S: str
        :rtype: str
        """
        l = len(S)
        num = [ord(char) - ord("a") for char in S] + [0]
        MASK = 0xFFFFFFFF
        BASE = 26
        def valid(L):
            seen = {}
            code = 0
            base_highest = 1
            for i in range(L - 1):
                code = (code * BASE + num[i]) & MASK
                base_highest = (base_highest * BASE) & MASK
            for i in range(L - 1, l):
                code = ((code - base_highest * num[i - L]) * BASE + num[i]) & MASK
                if code in seen:
                    return (seen[code], i)
                seen[code] = i
        
        left, right = 1, l - 1
        result = ""
        while left <= right:
            mid = (left + right) / 2
            pos = valid(mid)
            if not pos:
                right = mid - 1
            else:
                pos1, pos2 = pos
                while pos2 + 1 < l and S[pos1+1] == S[pos2+1]:
                    mid, pos1, pos2 = mid+1, pos1+1, pos2+1
                left = mid + 1
                result = S[pos2-mid+1 : pos2+1]
        return result
        

```
