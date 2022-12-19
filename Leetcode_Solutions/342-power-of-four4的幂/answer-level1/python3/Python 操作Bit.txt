### 解题思路
mask表示1,4,16,32,....
每次循环mask都通过移位2达到4的power，如果num是4的power，那么num一定会有一次等于mask
### 代码

```python3
class Solution:
    def isPowerOfFour(self, num: int) -> bool:
        mask = 1
        i = 0
        while i < 16:
            if num == mask:
                return True
            mask = mask << 2
            i += 1
        return False
```