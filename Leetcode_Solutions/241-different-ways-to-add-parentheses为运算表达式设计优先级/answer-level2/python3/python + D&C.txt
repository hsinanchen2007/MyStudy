```python
class Solution:
    def compute(self, left, right, computor):
        if computor == '+':
            return left + right
        elif computor == '-':
            return left - right
        elif computor == '*':
            return left * right
        

    def diffWaysToCompute(self, input: str) -> List[int]:
        # backtracking
        if input[0] == '-': return input # corner case -1
        res = []
        for i in range(len(input)):
            if input[i] in ['+', '-', '*']:
                left = self.diffWaysToCompute(input[:i])
                right = self.diffWaysToCompute(input[i + 1:])
                for l in left:
                    for r in right:
                        res.append(self.compute(l, r, input[i]))
        if len(res) == 0: return [int(input)]
        return res
```