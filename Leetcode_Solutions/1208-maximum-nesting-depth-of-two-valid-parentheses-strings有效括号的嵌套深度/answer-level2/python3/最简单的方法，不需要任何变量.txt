代码思路：只需要判断当前字符与前一个字符的关系
两个单括号组成的情况有四种:'((', '))', '()', ')('
前两种情况，这两个单括号肯定不能在同一子序列中，因为那样会加深字符串深度，所以分别分到A，B组
后两种情况，分到同一组不会加深字符串深度，所以可以分到同一组
```
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        res = [0]*len(seq)
        for i in range(1, len(seq)):
            if seq[i] == seq[i-1]: # 前后分到不同组
                res[i] = 1 - res[i-1]
            else:
                res[i] = res[i-1] # 前后同组
        return res
```
