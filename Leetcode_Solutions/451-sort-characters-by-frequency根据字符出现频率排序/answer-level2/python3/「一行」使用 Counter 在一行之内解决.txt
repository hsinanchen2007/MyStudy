## Counter
+ 简单介绍一下 `Counter`。
+ 它是一个用来统计出现次数的类，在 `collections` 包里。
+ `Counter(s)` 就可以返回一个类似字典的结构，键是`s`中的项，值是这个项出现的次数。
+ 对于字符串，就是每个字符和它出现的次数。
+ `Counter`类有一个函数，叫`most_common(int n)`，可以返回最常出现的几项，如果不加参数，就全部返回，相当于按照出现次数从大到小输出。
+ 输出的格式形如 `[('s',4),('a',3)]`。
+ 即字符`s`出现4次，`a`出现3次。

## 思路
+ 将字符串使用`Counter`处理一下。
+ 按照`most_common()`按照出现次数将它们返回。
+ 然后将字符乘以它们的出现次数。
+ 再利用字符串的`join()`函数将它们通通连接起来。


## 代码
```python
from collections import Counter

class Solution:
    def frequencySort(self, s: str) -> str:
        return ''.join(i * j for i,j in Counter(s).most_common())
```