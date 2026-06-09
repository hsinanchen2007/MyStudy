# 思路
+ 统计每个数的频率，输出最大的几个，这完全迎合了Python中的Counter类，调用其的几个方法即可。
# 什么是Counter？
+ Counter 是一个在collections包里的类，正如其名，是一个用于计数的工具。
+ 我们可以用Counter(nums)这样的构造函数构造一个Counter类，其中nums是一个列表。
+ 构造好的Counter实例可以看作一个字典，键是nums的每一项，值是它的出现次数。
+ 如果上面的叙述让你感到很混乱的话，我不妨举个例子。
+ 如果一个列表`a = [1,1,3,4,3]`，你想要统计每项的出现次数，那么你使用`b = Counter(a)`，那么这时候b就像一个这样的字典`{1:2,3:2,4:1}`，表示数字1出现了2次，数字3出现了2次，数字4出现了1次。
+ 还是很好理解的吧？
+ 可是题目里要我们输出的是最多的K项
+ 这时候可以应用Counter的一个函数，`most_common(k)`
+ 这个函数就是返回最多出现的K项
+ 但是返回的形式是一个元祖列表，类似`[(1,2),(3,2),(4,1)]`的形式
+ 我们只需要键也就是第一项，所以要使用列表生成式处理一下即可。
# 代码
```python
from collections import Counter
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        return [i[0] for i in Counter(nums).most_common(k)]
```