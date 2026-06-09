### 解题思路
原来贪心算法只体现在：当20块钱时，优先找钱10和5？？
下次试试用计数的，five = 0, ten = 0这种……
![image.png](https://pic.leetcode-cn.com/808e5980210c19ee763a1ef5ab3c37a5908d428832d2d3f4fad7a9b04387e092-image.png)

### 代码

```python3
class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        res = []
        for b in bills:
            res.append(b)
            if b == 10:
                try:
                    res.remove(5)
                except:
                    return False
            if b == 20:
                try:
                    if 5 in res and 10 in res:
                        res.remove(5)
                        res.remove(10)
                    else:
                        res.remove(5)
                        res.remove(5)
                        res.remove(5)
                except:
                    return False
    
        return True
```