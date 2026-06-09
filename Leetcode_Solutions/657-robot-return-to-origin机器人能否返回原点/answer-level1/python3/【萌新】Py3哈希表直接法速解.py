### 解题思路
创建哈希表，记录每次按键的次数，比较U D 和R L 的次数是否相同，如果不相同，不能回到(0,0)

### 代码

```python3
class Solution:
    def judgeCircle(self, moves: str) -> bool:
        dic={'R':0,'L':0,'U':0,'D':0}
        for i in moves:
            dic[i]+=1
        if dic['R']!=dic['L'] or dic['U']!=dic['D']:
            return False
        return True
        
```