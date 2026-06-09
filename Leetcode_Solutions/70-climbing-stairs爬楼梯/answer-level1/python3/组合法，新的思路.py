## 话不多说先上代码

```python []
import math

class Solution:
    def climbStairs(self, n: int) -> int:
        result = 1
        for i in range(1, int(n / 2 + 1)):
            result += math.factorial(n - i) / math.factorial(i) / math.factorial(n - i * 2)
        return int(result)
```

## 思路类似求组合数，比如 n = 5 时全部的可能性如下：
```
[1,1,1,1,1]
[2,1,1,1]
[1,2,1,1]
[1,1,2,1]
[1,1,1,2]
[2,2,1]
[2,1,2]
[1,2,2]
```
#### 2 的个数为 1 的情况有：
```
[2,1,1,1]
[1,2,1,1]
[1,1,2,1]
[1,1,1,2]
```
共四种，也就是公式：
![279759ee3d6d55fb34fde7ec66224f4a21a4ddc5.jpg.png](https://pic.leetcode-cn.com/90e251db7d22b9a1ac92d4928bac661f431dbc0f1cc45305aa0b2a8d7da3462e-279759ee3d6d55fb34fde7ec66224f4a21a4ddc5.jpg.png)
n = 4, m = 1

#### 2 的个数为 2 的情况有 3 种
也就是上述公式中， n = 3, m = 2
#### 2 的个数的取值范围为 [0, int(n / 2)]
2 的个数是 0 时只有一种可能性，所以 result 初始值为 1，上边代码 for 直接略去 0 的情况，从 1 开始，2 的取值范围左右都为闭，所以 range(1, int(n / 2 + 1))
#### 最后在循环中用公式求出个数累加到 result

题解中大部分是动态规划或者斐波拉契数列，这个也算是一个不同的思路，提供给大家参考。