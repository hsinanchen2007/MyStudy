### 解题思路
打表二分查找

### 代码

```python []
class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        d = [
            12, 23, 34, 45, 56, 67, 78, 89, 123, 234, 345, 456, 567, 678, 789, 1234, 2345,
            3456, 4567, 5678, 6789, 12345, 23456, 34567, 45678, 56789, 123456, 234567,
            345678, 456789, 1234567, 2345678, 3456789, 12345678, 23456789, 123456789
        ]
        return d[bisect.bisect_left(d, low): bisect.bisect(d, high)]
```

![image.png](https://pic.leetcode-cn.com/e75b3e36fbc1274446b4b2c85fd5095caaf56e6fd6890dd710c256b3397d7d03-image.png)
