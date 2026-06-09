# 看见1就说1个1，看见n个1就说n个1，看见其他数字也一样，例如：1121 -> 2个1 1个2 1个1 -> 211211。这道题目用groupby方法做就很容易实现，因为这个方法已经帮我们把数的步骤给解决了。使用了groupby方法后，效果为：1121 -> [['1', '1'], ['2'], ['1']] -> 我们只需要把groupby后的每个子数组长度放在前，元素放在后，拼接起来即可。

# ```python
from itertools import groupby

class Solution:
    def countAndSay(self, n: int) -> str:
        result = '1'
        for i in range(1, n):
            result = ''.join([str(len(list(g))) + k for k, g in groupby(result)])
        return result
# ```
# 在想如果面试的时候用这个方法会不会被打？😹