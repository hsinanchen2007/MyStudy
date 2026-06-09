### 解题思路
![QQ截图20200214173013.png](https://pic.leetcode-cn.com/01dadb9dd636089b557d20d358b406aefa67306cfe84396eb8801fd1fe33ca9d-QQ%E6%88%AA%E5%9B%BE20200214173013.png)


### 代码

```python3
class Solution:
    def reverseLeftWords(self, s: str, n: int) -> str:
        return s[n:]+s[:n]
```