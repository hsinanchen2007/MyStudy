### 解题思路
O(1)的一般就是公式了……题目说的有点多，不提醒还真想不到
数学归纳法：
k=x
k+1=x+1 当x=9时：k+1=1
k+2=x+2 或 2
显然 k%9可以推测，根据0-9调整表达式

### 代码

```python3
class Solution:
    def addDigits(self, num: int) -> int:
        return (num-1)%9+1 if num!=0 else 0
```