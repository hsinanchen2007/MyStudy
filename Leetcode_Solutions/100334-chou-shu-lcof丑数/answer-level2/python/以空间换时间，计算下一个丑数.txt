### 解题思路
计算下一个丑数

### 代码

```python
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        p2,p3,p5=0,0,0
        uglyNumber=[1]#存储计算的丑数
        while len(uglyNumber)<n:
            uglyNumber.append(min(uglyNumber[p2]*2,uglyNumber[p3]*3,uglyNumber[p5]*5))
            if uglyNumber[-1]==uglyNumber[p2]*2: p2+=1
            if uglyNumber[-1]==uglyNumber[p3]*3: p3+=1
            if uglyNumber[-1]==uglyNumber[p5]*5: p5+=1
        return uglyNumber[-1]

```