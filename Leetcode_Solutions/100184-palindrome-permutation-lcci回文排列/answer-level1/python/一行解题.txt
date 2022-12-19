### 解题思路
最多只能有一个字符奇数次出现。列表解析求模2之和即可。

### 代码

```python3
class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        return sum([s.count(x)%2 for x in set(s)])<=1
```