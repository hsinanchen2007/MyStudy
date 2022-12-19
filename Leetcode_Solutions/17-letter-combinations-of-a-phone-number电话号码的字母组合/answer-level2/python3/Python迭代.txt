### 解题思路
逐位处理，新的结果是在前面结果的基础上与新一位的所有组合，两重for循环列表推导式即可。

### 结果
![image.png](https://pic.leetcode-cn.com/e70071ef7bfbad47a6143d8be208e6108fb13c2cf14bbcee261df0a398c9d063-image.png)


### 代码

```python3
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        maps = {'2':'abc','3':'def','4':'ghi','5':'jkl','6':'mno','7':'pqrs','8':'tuv','9':'wxyz'}
        res = ['']
        for digit in digits:
            res = [old + new for old in res for new in maps[digit]]
        return res
```