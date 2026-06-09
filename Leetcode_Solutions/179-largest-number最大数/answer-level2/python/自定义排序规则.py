## 思路：

自定义排序规则

1. 使用`cmp_to_key`
2. 类的魔法方法

详细可以看我写的关于 [`Python`排序](https://zhuanlan.zhihu.com/p/77515576)总结

------

`n`为数组长度

`k`为数字字符串的平均长度

因为排序时间复杂度 `nlogn`

有因为字符串之间也要比较，所以时间复杂度为 $knlogn$

空间复杂度：$O(n)$

`Java` 也差不多方法.

## 代码：

**使用`cmp_to_key`**

```python
class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        from functools import cmp_to_key
        def helper(x, y):
            if x + y > y + x:
                return -1
            elif x + y < y + x:
                return 1
            else:
                return 0

        return "".join(sorted(map(str, nums), key=cmp_to_key(helper))).lstrip("0") or "0"
```

**类的魔法方法，两种写法**

写法一：

```python
class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        class cmp_large:
            def __init__(self, num):
                self.num = str(num)

            def __lt__(self, other):
                return self.num + other.num > other.num + self.num

            def __gt__(self, other):
                return self.num + other.num < other.num + self.num

            def __eq__(self, other):
                return self.num + other.num == other.num + self.num

        nums = [cmp_large(num) for num in nums]
        return "".join(a.num for a in sorted(nums)).lstrip("0") or "0"
```

写法二：

```python
class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        class large_num(str):
            def __lt__(self, other):
                return self + other > other + self
        return "".join(sorted(map(str, nums), key=large_num)).lstrip("0") or "0"
```

