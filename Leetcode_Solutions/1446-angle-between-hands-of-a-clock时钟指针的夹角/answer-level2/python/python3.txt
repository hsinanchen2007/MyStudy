### 解题思路
每分钟，分针移动6度，时针移动0.5度
追及问题：当6y=30x+0.5y，等式左边是分针走过的角度，等式右边是时针走过的角度，等式满足的时候就是追上了，变形一下5.5y-30x=0，这就是追上的情况，所以，现在给出两个值，时针和分针的数值，由于是没有追上，所以既然现在要求相差多少，那就是这个5.5y-30x=△，这就是现在相差的角度

### 代码

```python3
class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        cha=abs(5.5*minutes-30*hour)
        if cha>180:
            cha=360-cha
        return cha
```