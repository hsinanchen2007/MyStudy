#### 思路
三个数有两个间隔，根据间隔的空位情况分成以下三种：
![三种情况](https://pic.leetcode-cn.com/cfa50f0881b0fa63b44151c0731e9cfa96b1ac03065f0516dac341a358c56dea-1.png)
1. `xyz`连续，无法移动，返回`[0,0]`；
2. `xy`或者`yz`中至少有一组之间有一个空位，将远处的数移到该空位即可，`minimum_moves = 1`；
3. 两个间隔中的空位均大于1,则至少移两次，`minimum_moves = 2`,情况2或情况3两端向中间逐步收缩即可`maximum_moves = (y-x-1)+(z-y-1)`。
#### 代码
```
class Solution:
    def numMovesStones(self, a: int, b: int, c: int) -> List[int]:
        tmp = [a,b,c] # 先对xyz赋值
        tmp.sort()
        x,y,z = tmp[0],tmp[1],tmp[2]
        if x + 1 == y and y + 1 == z: # a,b,c连续
            return [0,0]
        else:
            if y-x == 2 or z-y == 2 or (x+1 == y or y + 1 == z):  # 中间隔一个或者有两个挨着
                minimum_moves = 1
            else:
                minimum_moves = 2
            maximum_moves = (y-x)+(z-y)-2
        return [minimum_moves,maximum_moves]
```
#### 复杂度分析
- 时间复杂度：O（1），三个数的排序时间是固定的。
- 空间复杂度：O（1），使用了常数空间存储变量。
