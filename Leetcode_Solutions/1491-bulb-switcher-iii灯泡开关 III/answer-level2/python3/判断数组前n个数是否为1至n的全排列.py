### 解题思路
蓝灯状态++ 
= 第i个灯泡亮(状态刷新) + 前i个灯泡都亮(旧状态)
= 某数`x`加入数组lst时, 使得`1`, `2`, .., `x`在新lst中恰好出现一次
= 在位置`index`处, lst是否为`1`, `2`, .., `index`的全排列(用累加和的方式验证)
= lst前`index`的和 == `index * (1 + index) / 2`

对于已经亮的前n个灯, 它们的亮灯过程不用再去需要考虑了.

### 代码

```python3
class Solution:
    def numTimesAllBlue(self, light: List[int]) -> int:
        s = t = count = 0
        for i in range(len(light)):
            s += i + 1      # 累加和
            t += light[i]   # 当前和
            if s == t:
                count += 1  # 蓝灯状态++
        return count
```