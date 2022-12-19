### 解题思路
求出字符串的全部排列，可以从一个字符的排列开始，不断添加新的字符，进行“滚雪球”的操作，如果到达最后一个字符，则放入结果中。时间复杂度为O(3^N+4^M), N和M分别为对应3和4个字符的数字数量，空间复杂度为排列组合的个数，也为O(3^N+4^M)。

### 代码

```python3
class Solution:
    dic = {'2': "abc", '3':"def", '4': "ghi", '5': "jkl", '6': "mno", '7': "pqrs", '8': "tuv", '9': "wxyz"}
    def letterCombinations(self, digits: str) -> List[str]:
        n = len(digits)
        res = []
        def track(curstr, idx):
            if idx == n:
                res.append(curstr)
            else:
                for c in self.dic[digits[idx]]:
                    track(curstr+c, idx+1)
        if n > 0:
            track("", 0)
        return res
```