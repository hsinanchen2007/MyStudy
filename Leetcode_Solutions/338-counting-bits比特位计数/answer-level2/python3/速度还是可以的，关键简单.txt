![图片1.png](https://pic.leetcode-cn.com/6920300d7f2d486f3bde331438958a684272189f576957d1405195167cad7967-%E5%9B%BE%E7%89%871.png)

每进一位，就把前面的结果复制出来加上1，最后取前num+1个即可。发现速度比dp快，不知道是否偶然。

```
class Solution:
    def countBits(self, num: int) -> List[int]:
        n = num.bit_length() - 1
        res = [0, 1]
        for _ in range(n):
            res.extend([j + 1 for j in res])
        return res[:num + 1]
```
