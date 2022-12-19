![u=1057103716,2393190378&fm=26&gp=0.jpg](https://pic.leetcode-cn.com/aaad7c6c22d88a7977a2e3525315a6872681c2d7f14f41f9e2876762d7fddb53-u=1057103716,2393190378&fm=26&gp=0.jpg)

### 废话少说：

```
class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        return reduce(lambda x,y:x*y,[int(i) for i in str(n)])-sum([int(i) for i in str(n)])
```
