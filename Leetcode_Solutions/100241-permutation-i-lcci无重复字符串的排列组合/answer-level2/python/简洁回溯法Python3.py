```python3
class Solution:
    def permutation(self, S: str) -> List[str]:
        res = []
        self.helper(S, '', res)
        return res

    def helper(self, S, path, res):
        if not S:
            res.append(path)
            return
        for i in range(len(S)):
            self.helper(S[:i]+S[i+1:], path+S[i], res)