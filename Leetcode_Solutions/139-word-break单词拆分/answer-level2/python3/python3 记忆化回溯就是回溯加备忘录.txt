### 解题思路
此处撰写解题思路
@functools.lru_cache(None) 使用记忆化，也可以自己写，，但是好久没写了，，还真有点头大。。
下面注释的代码是从一个[道友](https://leetcode-cn.com/problems/word-break/solution/dong-tai-gui-hua-ji-yi-hua-hui-su-zhu-xing-jie-shi/)那里学过来的。
### 代码

```python3
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        self.ans = False
        import functools
        @functools.lru_cache(None)
        def helper(s):
            if not s:
                self.ans = True
            
            for i in wordDict:
                if self.ans:
                    break
                if s.startswith(i):
                    helper(s[len(i):])

        helper(s)   
        return self.ans

        # import functools
        # @functools.lru_cache(None)
        # def back_track(s):
        #     if not s:
        #         return True
        #     res=False
        #     for i in range(1,len(s)+1):
        #         if s[:i] in wordDict:
        #             res=back_track(s[i:]) or res
        #     return res
        # return back_track(s)


```