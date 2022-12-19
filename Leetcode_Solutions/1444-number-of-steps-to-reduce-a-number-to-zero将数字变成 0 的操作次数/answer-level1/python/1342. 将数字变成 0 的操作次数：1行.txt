![image.png](https://pic.leetcode-cn.com/90a9d2fea26a78f34cd73aa66fd2c654f2876e4ec4ee930415d78694fcf83fa6-image.png)

计数迭代器

```python []
class Solution:
    def numberOfSteps (self, num: int) -> int:
        for ans in itertools.count():
            if not num:
                return ans
            num = num - 1 if num & 1 else num // 2
```

二进制计数

```python []
class Solution:
    def numberOfSteps (self, num: int) -> int:
        return bin(num).count('1') + num.bit_length() - 1
```
