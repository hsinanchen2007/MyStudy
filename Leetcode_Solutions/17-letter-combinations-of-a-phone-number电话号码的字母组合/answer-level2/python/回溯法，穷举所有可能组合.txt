思路：将第一个数字映射的字母作为初始result，暴力循环result中全部元素和后一个数字映射的字母组合，并更新result(删除已处理组合+添加新组合)。
注意：由于不断更新result，循环result时一定采用python列表的复制方法，防止陷入无限循环。

```
class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        num_str = [['a', 'b', 'c'], ['d', 'e', 'f'],
                   ['g', 'h', 'i'], ['j', 'k', 'l'],
                   ['m', 'n', 'o'], ['p', 'q', 'r', 's'],
                   ['t', 'u', 'v'], ['w', 'x', 'y', 'z']]
        res = []
        if not digits:
            return res
        res += num_str[int(digits[0]) - 2]
        for i in digits[1:]:
            for item in res[:]:     # 复制旧的res，防止陷入无限循环
                res.remove(item)    # 删掉被更新的组合
                for j in num_str[int(i) - 2]:
                    res.insert(0, item+j)   # 添加新组合
        return res
```
