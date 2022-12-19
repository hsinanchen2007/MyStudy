![image.png](https://pic.leetcode-cn.com/0d50fcb8b2554e91a6e413356a386745f1853254b95497ffb02f310d314b2838-image.png)


```
from functools import lru_cache

'''
递归进行压缩，把s切分成两半，左边一半如果能够按照整倍数压缩，就进行压缩，先把左边一半变成最短的，
然后递归处理右边一半，把两半都处理完之后的字符串拼接回来，最短的拼接字符串就是答案，判断能不能进行
整倍数压缩的时候，问题转换为找串的重复子串问题
'''

class Solution:

    #  返回最短的以倍数压缩后的字符串，不能压缩返回原字符串
    @lru_cache(typed=False)
    def compress(self, s: str):
        if s == '' or len(s) == 1:
            return s

        t = s + s
        n = len(s)
        ans = s

        # 找重复子串位置
        idx = t.find(s, 1)
        if idx == n:
            return ans

        cnt = len(s) // idx
        encode_str = self.encode(s[:idx])
        ss = str(cnt) + '[' + encode_str + ']'
        if len(ss) < len(ans):
            ans = ss
        return ans

    @lru_cache(typed=False)
    def encode(self, s: str) -> str:
        #print(s)
        if s == '' or len(s) == 1:
            return s

        ans = s
        for i in range(0, len(s)):
            ss = self.compress(s[:i+1]) + self.encode(s[i+1:])
            if len(ss) < len(ans):
                ans = ss
        return ans
```
