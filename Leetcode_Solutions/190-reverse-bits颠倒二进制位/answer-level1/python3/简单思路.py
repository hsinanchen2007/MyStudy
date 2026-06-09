### 解题思路
此处撰写解题思路
左移就是乘以2
数字为32位
### 代码

```python3
class Solution:
    def reverseBits(self, n: int) -> int:
        a=0
        for i in range(32):
            a=a*2
            if n%2==1:
                a=a+1
            n=n//2
        return a

```