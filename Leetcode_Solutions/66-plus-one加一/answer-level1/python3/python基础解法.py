### 解题思路
利用列表生成式，先将列表join在一起加1在生成列表

### 代码

```python3
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        return [int(j) for j in str(int("".join([str(i) for i in digits])) + 1)]
```