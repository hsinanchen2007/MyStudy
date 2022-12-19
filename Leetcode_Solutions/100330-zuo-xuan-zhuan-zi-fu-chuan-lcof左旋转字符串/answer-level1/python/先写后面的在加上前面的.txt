### 解题思路
![code.PNG](https://pic.leetcode-cn.com/bd6d0558675051e1639dae98441d0c32d4a5689a5ba927c89e576d5f7f1e7fd9-code.PNG)
先写后面n个的在加上前面的

### 代码

```python3
class Solution:
    def reverseLeftWords(self, s: str, n: int) -> str:
        result =  s[n:]
        for i in range(n):
            result = result+s[i]
        return result
```