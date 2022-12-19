这道题使用后缀数组无法通过但使用二分法可以通过。具体的做法是：在[0,n)的区间内使用二分法寻找最长重复子串的长度，对于一个长度k，判断字符串中是否存在长度为k的子串的具体做法为：将每一个长度为k的字符串看成一个26进制的数，然后将其转化为十进制，由于结果可能很大，所以每次运算后都将结果对一个很大的数取模。然后判断这个数是否出现过，如果出现过，则说明存在长度为k的子串；如果没出现过，则将其存入一个set。由于每次都可以将前一个子串的第一个字符去掉然后加上后一个字符得到下一个26进制数，所以进制转换的开销很小。  
```Python
class Solution:
    def longestDupSubstring(self, S: str) -> str:
        import functools
        A = [ord(c) - ord('a') for c in S]
        mod = 2**63 - 1
        n = len(S)
        def test(l):
            p = pow(26,l,mod)
            cur = functools.reduce(lambda x,y:(x*26+y)%mod,A[:l])
            seed = {cur}
            for index in range(l,n):
                cur =(cur * 26 + A[index] - A[index-l] * p) % mod
                if cur in seed:
                    return index - l + 1
                seed.add(cur)
            return -1
        low,high = 0,n
        res = 0
        while low < high:
            mid = (low + high + 1) // 2
            pos = test(mid)
            if pos != -1:
                low = mid
                res = pos
            else:
                high = mid - 1
        return S[res:res+low]
```