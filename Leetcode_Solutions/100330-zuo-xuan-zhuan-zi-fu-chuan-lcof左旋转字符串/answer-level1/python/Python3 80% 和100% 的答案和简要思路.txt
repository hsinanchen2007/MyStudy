### 解题思路
这个其实很直接，因为如果输入大于len(s)，就是等于转一圈之后再走n-len(s)，所以刚开始先把转的圈去掉，就取n/len(s)的余数，然后下一行就切片，得出最终的结果

### 代码

```python3
class Solution:
    def reverseLeftWords(self, s: str, n: int) -> str:
        n %= len(s)
        return s[n:]+s[:n]

```