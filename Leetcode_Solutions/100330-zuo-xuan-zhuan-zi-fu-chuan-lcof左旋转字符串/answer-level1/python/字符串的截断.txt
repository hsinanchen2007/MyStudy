### 解题思路
直接利用将字符串截断就可以，注意下标值。
用时较多，击败60%。

### 代码

```python3
class Solution:
    def reverseLeftWords(self, s: str, n: int) -> str:
        return s[n:] + s[0:n]
```