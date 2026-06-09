### 解题思路
两种方法比较字符串顺序：
1. `int(s1 + s2) < int(s2 + s1)`，非常直观，拼贴两个字符串看大小即可
    a. 用`functools.cmp_to_key`来实现
    b. 用继承`str`的`__lt__(x, y)`方法来实现
2. 一位一位比较，若`len(s)`位之后没有数值了，就复制自身继续比较

### 代码
1.a 用`functools.cmp_to_key`来实现
返回大于0的值代表`x>y`，令x排在y后面
[cmp_to_key 介绍](https://www.cnblogs.com/for-master/p/10281958.html)
```python3
class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        from functools import cmp_to_key
        key = cmp_to_key(lambda x, y: int(y+x) - int(x+y))
        res = ''.join(sorted(map(str, nums), key=key)).lstrip('0')
        return res or "0"
```

1.b 用继承`str`的`__lt__(x, y)`方法来实现
返回大于0的值时代表`x<y`，令x排在y前面
[比较运算符重载介绍](https://zhuanlan.zhihu.com/p/24567545)
[意外看见的装饰器模式辅助重载运算符但我还没咋看懂并且觉得metaclass也能实现类似功能？](https://www.cnblogs.com/byron0918/p/10209341.html)
```python3
class LargeNumKey(str):
    def __lt__(x, y):
        return x+y > y+x

class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        res = ''.join(sorted(map(str, nums), key=LargeNumKey)).lstrip('0')
        return res or '0'
```
2 一位一位比较，若`len(s)`位之后没有数值了，就复制自身继续比较
```python3
    nums = list(map(str, nums))
    maxlen = max(len(s) for s in nums)
    key = lambda s:s*(maxlen//len(s)+1)
    res = ''.join(sorted(nums, key=key, reverse=True)).lstrip('0')
    return res or "0"
```
        