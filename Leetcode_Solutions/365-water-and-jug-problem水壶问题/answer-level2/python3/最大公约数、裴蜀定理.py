用到一个基本的数论定理，给定两个整数ｘ和ｙ，ｘ和ｙ的最大公约数是ｄ，另一个整数ｚ，存在两个整数ｍ和ｎ使得ｍ＊ｘ＋ｎ＊ｙ＝ｚ的充分必要条件是ｚ％ｄ＝＝０。
当然，要考虑一些其他条件，比如超过两个杯子容量之和的数是无法表示出来的，还有值为0时的特殊情况（我经常考虑不全这种特殊情况，一般是靠提交试错的：(）。
代码如下
```python3
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        c = self.greatestCommonDivisor(x, y)
        if c == 0:
            if z == 0:
                return True
            else:
                return False
        else:
            return z % c == 0 and x + y >= z

    def greatestCommonDivisor(self, x: int, y: int) -> int:
        if x == 0 or y == 0:
            return 0
        else:
            if x < y:
                x, y = y, x
            while x % y != 0:
                x, y = y, x % y
            return y
```