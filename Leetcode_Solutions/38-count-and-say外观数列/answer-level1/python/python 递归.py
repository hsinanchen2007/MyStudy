```
class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        if n == 1:
            return '1'
        pred = self.countAndSay(n-1)
        cur = '*'
        num = 0
        mystr = ''
        for ch in pred:
            if ch != cur:
                if num!=0:
                    # 当新出现的字符与之前遇到的字符不一致时，mystr更新
                    mystr += str(num)+cur

                # 第一个字符 特判
                num = 1
                cur = ch
            else:
                num += 1

        if num:
            mystr += str(num) + cur
        return mystr
```
