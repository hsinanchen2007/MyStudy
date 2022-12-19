```python
class Solution:
    def printNumbers(self, n: int) -> List[int]:
        i = 1
        res = []
        while i < 10 ** n:
            res.append(i)
            i += 1
        return res
```

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)