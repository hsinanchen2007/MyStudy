
### 代码

```python3
class Solution:
    def numMovesStones(self, a: int, b: int, c: int) -> List[int]:
        d1=abs(a-b)
        d2=abs(a-c)
        d3=abs(b-c)
        mind=min([d1,d2,d3])
        maxd=max([d1,d2,d3])
        if mind==1 and maxd==2:
            return [0,0]
        elif mind<3:
            return [1,maxd-2]
        else:
            return [2,maxd-2]
```

![image.png](https://pic.leetcode-cn.com/aab8fc2f1ed970192fe3596610afa9ec25272abe4a0d907ebf7166129fd2d7fe-image.png)
