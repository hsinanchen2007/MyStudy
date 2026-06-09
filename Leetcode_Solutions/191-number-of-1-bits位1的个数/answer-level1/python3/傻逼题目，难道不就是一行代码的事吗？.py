### 解题思路
执行用时 :
36 ms
, 在所有 python3 提交中击败了
61.36%
的用户
内存消耗 :
12.6 MB
, 在所有 python3 提交中击败了
100.00%
的用户
### 代码

```python3
class Solution:
    def hammingWeight(self, n: int) -> int:
        return bin(n).count("1")
```