### 解题思路
这个题目主要考察数学分析，
每个2和5提供一个10，而每5个数必有一个2，因此只需要分析5的数量
同时要考虑到25,125等等一个数字有很多5的情况


### 代码

```python3
class Solution:
    def trailingZeroes(self, n: int) -> int:
        c = 0
        while n > 0:
            c += n // 5
            n //= 5
        return c

```