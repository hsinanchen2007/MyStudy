### 解题思路
range这个在这里简单，复杂度不是最优，也不错。
执行用时 :36 ms, 在所有 Python3 提交中击败了81.36%的用户
内存消耗 :13.4 MB, 在所有 Python3 提交中击败了100.00%的用户

方法2：等差数列求和公式
s = n(n+1)/2
class Solution:
    def sumNums(self, n: int) -> int:
        if n <= 1:
            return n
        else:
            return int(n*(n+1)/2)

### 代码

```python3
class Solution:
    def sumNums(self, n: int) -> int:
        return sum(range(n+1))

        
```