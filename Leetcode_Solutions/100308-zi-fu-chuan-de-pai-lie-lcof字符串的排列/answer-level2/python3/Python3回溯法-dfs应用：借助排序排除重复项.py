```python
class Solution:
    def permutation(self, s: str) -> List[str]:
        res = []
        ## 先排好序，借助排序的字符串减少高效的递归重复答案，详见dfs函数。
        s = sorted(s)
        self.dfs(s, '', res)
        return res
     
    def dfs(self, s, path, res):
        if not s:
            res.append(path)
            return
        for i in range(len(s)):
            ## 下一次回溯排除当前时刻和上一时刻相同，因为这样子遍历出来的解和之前求出来的重复了
            if i > 0 and s[i-1] == s[i]:
                continue
            self.dfs(s[:i]+s[i+1:], path+s[i], res)
