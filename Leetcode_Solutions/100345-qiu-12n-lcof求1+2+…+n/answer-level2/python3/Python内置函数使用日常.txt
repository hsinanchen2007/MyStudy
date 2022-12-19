### 解题思路
此处撰写解题思路
利用range创建列表，再使用内置函数sum()即可
p.s: 不要重复造轮子
### 代码

```python3
class Solution:
    def sumNums(self, n: int) -> int:
        return sum(range(1, n + 1))
```