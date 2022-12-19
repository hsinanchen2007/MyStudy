
递推

```
class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        if n < 1:
            return None
        if n == 1:
            return '1'
        if n == 2:
            return '11'
        pre = '11'
        count = 2
        while count < n:
            res = ''
            preChar = pre[0]
            nChar = 1
            for char in pre[1:]:
                if char == preChar:
                    nChar += 1
                else:
                    res = res + str(nChar) + preChar
                    nChar = 1
                    preChar = char
            # 走到最后
            res = res + str(nChar) + preChar
            count += 1
            pre = res
        return res

```
