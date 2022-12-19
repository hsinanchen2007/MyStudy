### 思路

**数学**

```
从 1 遍历到 sqrt(x)，找到最接近的两个因数。
其实从 sqrt(x) 倒过来遍历会更快。
```

**时间复杂度:** O(sqrt(n))
**空间复杂度:** O(1)

### Python3代码

```python
class Solution:
    def closestDivisors(self, num: int) -> List[int]:
        import math
        num1, num2 = num + 1, num + 2
        ans1 = self.crack(num1)
        ans2 = self.crack(num2)
        res = []
        if abs(ans1 - int(num1 / ans1)) < abs(ans2 - int(num2 / ans2)):  # int
            res.append(ans1)
            res.append(int(num1 / ans1))
            return res
        else:
            res.append(ans2)
            res.append(int(num2 / ans2))
            return res
    
    # calculate factor
    def crack(self, integer):
        factor1, factor2 = 1, integer
        for i in range(1, int(math.sqrt(integer)) + 1):  # range: [1, sqrt(x) + 1)
            if int(integer / i) == integer / i:  # i is factor
                if integer / i - i < factor2 - factor1:
                    factor1, factor2 = i, integer / i
        return factor1
```


[GitHub](https://github.com/Wonz5130/LeetCode-Solutions)