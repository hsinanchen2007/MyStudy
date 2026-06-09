![image.png](https://pic.leetcode-cn.com/eaf01a46346a4c0ca41852472cfe8a44b18ce97bb36b1627fa85bc4af047cab5-image.png)

集合取交。

```python []
class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        d = set()
        for i in arr:
            if {i * 2, i / 2} & d:
                return True
            d.add(i)
        return False
```