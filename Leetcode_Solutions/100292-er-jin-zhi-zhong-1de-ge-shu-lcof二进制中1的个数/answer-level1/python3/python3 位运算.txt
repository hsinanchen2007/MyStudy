### 解题思路
1 位运算方式才能全过
2 辗转相除计数法过41个，如有道友有python3 解法欢迎留言交流


### 代码

```python3
class Solution:
    def hammingWeight(self, n: int) -> int:
        count=0
        while n:
            count+=n&1
            n>>=1
        return count

```