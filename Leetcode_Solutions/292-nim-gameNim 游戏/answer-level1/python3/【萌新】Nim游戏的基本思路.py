### 解题思路
此处撰写解题思路
Nim游戏
如果你想输，很简单，只要最后一次你拿的时候，剩下4个你就会输
也就是说只要总数不是4的倍数，每次对手拿n个，你都拿4-n个，就一定会赢
### 代码

```python3
class Solution:
    def canWinNim(self, n: int) -> bool:
        return (n%4)!=0
```