```
class Solution:
    def longestWord(self, words: List[str]) -> str:
        # 通过排序优化，直接找到最优值
        # 利用分治方法，进行判断是否包含此串
        words = sorted(words, key= lambda x: (-len(x), x))
        def dfs(words, word):
            for i in range(len(word)):
                if word[:i] in words:
                    if len(word[i:]) < len(words[-1]):
                        return False
                    if word[i:] in words or dfs(words, word[i:]):
                        return True                    
            return False

        for idx, w in enumerate(words):
            if dfs(words[idx+1:], w):
                return w 
        return ''
```
