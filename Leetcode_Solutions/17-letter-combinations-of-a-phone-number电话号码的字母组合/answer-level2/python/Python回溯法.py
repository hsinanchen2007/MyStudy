### 解题思路
引用一段官方题解对于回溯法的介绍：回溯是一种通过**穷举**所有可能情况来找到所有解的算法。如果一个候选解最后被发现并不是可行解，回溯算法会舍弃它，并在前面的一些步骤做出一些修改，并重新尝试找到可行解。


### 代码

```python
class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        num2ch = {
            '2': ['a', 'b', 'c'],
            '3': ['d', 'e', 'f'],
            '4': ['g', 'h', 'i'],
            '5': ['j', 'k', 'l'],
            '6': ['m', 'n', 'o'],
            '7': ['p', 'q', 'r', 's'],
            '8': ['t', 'u', 'v'],
            '9': ['w', 'x', 'y', 'z']
        }
        def get_res(combination, digits):
            if digits == '':
                if combination != '':
                    res.append(combination)
                return 
            for ch in num2ch[digits[0]]:
                get_res(combination + ch, digits[1:])

        res = []
        get_res('', digits)
        return res 
```