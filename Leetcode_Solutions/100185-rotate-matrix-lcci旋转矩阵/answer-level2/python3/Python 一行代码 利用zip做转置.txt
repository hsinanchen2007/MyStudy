思路就是，先matrix[::-1]做上下翻转，然后用zip进行转置操作。
Tip: 这里没有返回值，所以对matrix[::]进行赋值，不然matrix不会变哦！！！

```
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        matrix[::] = zip(*matrix[::-1])
```
