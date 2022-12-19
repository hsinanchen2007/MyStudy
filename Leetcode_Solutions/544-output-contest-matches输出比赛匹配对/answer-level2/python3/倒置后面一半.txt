### 解题思路
以n=8为例，
第一次匹配是：(1,8),(2,7),(3,6),(4,5)，可以看出就是最后一半倒置了和前面一半组合。
有了这一点，编程就简单了，首先初始化一个数组，包含1到n所有的数字，然后不断倒置后面一半，
与前面一半组合，知道最后只剩下一个元素

时间复杂度NlogN

### 代码

```python3
"""
time: 
"""
class Solution:
    def findContestMatch(self, n: int) -> str:
        res = list(map(str, range(1, 1+n)))
        while n > 1:
            n = n//2
            res = ['(' + res[i] + ',' + res[-i-1] + ')' for i in range(n)]
        return res[0]

```