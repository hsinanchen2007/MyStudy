### 解题思路
看到有人说这不是回溯问题，这道题明明白白清清楚楚就是一道回溯问题
只不过因为传的参数是一个str,每次的str都是新的所以没有显式的去调用选择和撤销选择这两步

### 代码

```python3
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        # 回溯法模板
        '''
        result = []
        def backtrack(路径, 选择列表):
            if 满足结束条件:
                result.add(路径)
                return
            for 选择 in 选择列表:
                做选择
                backtrack(路径, 选择列表)
                撤销选择
        其核心就是 for 循环里面的递归，在递归调用之前「做选择」，在递归调用之后「撤销选择」，特别简单。
        for 选择 in 选择列表:
            # 做选择
            将该选择从选择列表移除
            路径.add(选择)
            backtrack(路径, 选择列表)
            # 撤销选择
            路径.remove(选择)
        '''
        # 字典模拟
        phone = {'2': ['a', 'b', 'c'],
            '3': ['d', 'e', 'f'],
            '4': ['g', 'h', 'i'],
            '5': ['j', 'k', 'l'],
            '6': ['m', 'n', 'o'],
            '7': ['p', 'q', 'r', 's'],
            '8': ['t', 'u', 'v'],
            '9': ['w', 'x', 'y', 'z']}
        # 回溯函数
        def backtrack(combination, digits):
            # 满足条件
            if len(digits) == 0:
                res.append(combination)
            else:
                for str in phone[digits[0]]:
                    # 做选择 下面这样写就错了，要传一个变量进去,因为str是不可变类型，所以每次都是一个新的str
                    # combination += str
                    # backtrack(路径, 选择列表)
                    backtrack(combination + str, digits[1:])
                    # 这里因为是字符串，每次都是新的字符串，所以不用撤销选择
        res = []
        if digits:
            backtrack("", digits)
        return res
```