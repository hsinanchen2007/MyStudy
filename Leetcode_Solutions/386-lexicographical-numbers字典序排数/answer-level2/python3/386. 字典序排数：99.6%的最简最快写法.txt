![image.png](https://pic.leetcode-cn.com/edb031903163ac9afc0048f2df2e515e87f46f2e62e932d2c9d0118c53ec5548-image.png)

`sorted()`函数可以直接对迭代器排序，最后返回数组，`key`直接取`str`就可以了。

```python []
class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        return sorted(range(1, n + 1), key = str)
```
