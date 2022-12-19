因为对回溯不是很熟悉，大概理解了回溯的基本思想，但硬是没能用代码实现。突然灵光一现，用了递归，感觉代码层面上更好理解吧。

递归的思路也很简单，用例子来说明步骤；

1、 求[['a', 'b', 'c'], ['d', 'e', 'f'], ['h', 'i', 'j']] ，数组的字母结合情况
2、 只需要知道  [['d', 'e', 'f'], ['h', 'i', 'j']] 的组合情况
3、 只需要知道 [['h', 'i', 'j']] 的组合情况，显然就是这个 ['h', 'i', 'j']
4、 然后反推，即可得到最终结果


实现代码示例：

```python
from typing import List


class Solution:
    LETTER_MAPPING = {'1': [], '2': ['a', 'b', 'c'], '3': ['d', 'e', 'f'],
                      '4': ['g', 'h', 'i'], '5': ['j', 'k', 'l'], '6': ['m', 'n', 'o'],
                      '7': ['p', 'q', 'r', 's'], '8': ['t', 'u', 'v'], '9': ['w', 'x', 'y', 'z']}

    def combinations(self, digits):
        if len(digits) == 1:
            return digits[0]
        
        results = self.combinations(digits[1::])
        return ["{}{}".format(s, b) for s in digits[0] for b in results]
    
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return

        digits = [Solution.LETTER_MAPPING[s] for s in digits]

        return self.combinations(digits)
```
