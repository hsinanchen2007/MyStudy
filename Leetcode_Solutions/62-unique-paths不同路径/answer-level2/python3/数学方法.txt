### 解题思路
题目所给的是机器人位于m*n的左上角 要到达右上角
可以理解为x,y坐标系中
机器人位于(0,0)点，想要到达(m-1,n-1)点，
运动期间只能向上或者向右移动。
即向上运动m-1次，向右运动n-1次，总共运动m+n-2次
Am+n-2 即 m+n-2一共有多少种排列组合方法 (若m+n-2次中每次和每次的选择都不一样)
然而 向上的选择有m-1次   向右的选择有n-1次
所以 需要除去重复的排列次数  向上Am-1 和 向右An-1
即 Am+n-2/(Am-1*An-1)
为最终次数

### 代码

```python3
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        import math
        return int(math.factorial(m+n-2)/(math.factorial(m-1)*math.factorial(n-1)))
```