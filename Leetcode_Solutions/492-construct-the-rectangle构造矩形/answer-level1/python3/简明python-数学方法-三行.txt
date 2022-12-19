通过对各种情况的假定和推导，我们可以发现，最终的结果，都会略小于该面积的平方根，因此我们只需要找到小于平方根最大的整数，就能够给出该问题的解答。
```
class Solution:
    def constructRectangle(self, area: int) -> List[int]:
        w = int (math.sqrt(area))
        while area%w != 0:
            w -= 1
        return area//w, w
```
