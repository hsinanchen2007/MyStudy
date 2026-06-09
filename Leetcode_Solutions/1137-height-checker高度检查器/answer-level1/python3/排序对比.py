* 执行用时 : 40 ms, 在Height Checker的Python3提交中击败了100.00% 的用户
* 内存消耗 : 13.1 MB, 在Height Checker的Python3提交中击败了100.00% 的用户

```
class Solution:
    def heightChecker(self, heights):
        result = 0
        for i, j in zip(heights, sorted(heights)):
            if i != j:
                result += 1
        return result
```