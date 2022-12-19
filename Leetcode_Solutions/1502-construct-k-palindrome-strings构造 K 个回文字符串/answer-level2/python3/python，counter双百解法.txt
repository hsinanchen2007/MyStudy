### 解题思路
先找出一对的元素，剩下的是不是一对的，一对的可以带一个单独的组成一个回文串
执行用时 :92 ms
在所有 Python3 提交中击败了100.00的用户
内存消耗 :14.5 MB
在所有 Python3 提交中击败了100.00%的用户
### 代码

```python3
class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        double = sum([i[1]//2 for i in collections.Counter(s).items() if i[1] >= 2])
        un = len(s) - double*2
        return un <= k <= len(s)
```