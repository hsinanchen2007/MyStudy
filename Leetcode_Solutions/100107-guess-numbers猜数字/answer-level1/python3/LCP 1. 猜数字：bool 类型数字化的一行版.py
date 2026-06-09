![image.png](https://pic.leetcode-cn.com/651876e91766629180e8cd98c7566ec672ead258818219a3a698719ac43e3454-image.png)

```py
class Solution:
    def game(self, g: List[int], a: List[int]) -> int:
        return (g[0] == a[0]) + (g[1] == a[1]) + (g[2] == a[2])
```
