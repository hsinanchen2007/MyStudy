### 解题思路
题给的循环终止条件是正整数，对应就是等差数列中起始项a1>0.0，初始化n=2，每次循环n+=1，得到整数a1则构造等差数列。最后将数组reverse。

### 代码

```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        res = []
        n = 2
        a1 = target
        while a1 > 0.0:
            a1 = target/n-(n-1)/2
            if a1%1 == 0.0 and a1 > 0.0:
                res.append(list(range(int(a1),int(2*target/n-a1)+1)))
            n += 1
        res.reverse()
        return res
```