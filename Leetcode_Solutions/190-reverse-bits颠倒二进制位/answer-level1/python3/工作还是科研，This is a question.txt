### 解题思路
![QQ截图20200118175051.png](https://pic.leetcode-cn.com/dc288cbf81feca13838e7d76bf5f0932e83dc5122a884934f941dbb25f5c41d5-QQ%E6%88%AA%E5%9B%BE20200118175051.png)
还有必要多bb?

### 代码

```python3
class Solution:
    def reverseBits(self, n: int) -> int:
        q=bin(n)[2:]
        str0=""
        for i in range(0,32-len(q)):
            str0+="0"
        q=str0+q
        p=q[::-1]
        return int(p,2)

```