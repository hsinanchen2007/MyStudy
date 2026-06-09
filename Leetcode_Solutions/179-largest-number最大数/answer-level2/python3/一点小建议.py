### 解题思路
1.虽然官方题解的写法让我大开眼界，但是个人觉得__lt__方法的返回值还是改成和小于的原意一样的吧，然后把sorted的reverse参数设置为True，这样排序的顺序也是大到小。
2.今天才知道富比较方法这个东西，在一个类里面重载__lt__、__gt__方法后，可以直接用<、>来比较两个类的大小关系，也可以将类传入sorted和sort函数的key参数中，用于类元素组成的序列等的排序。

### 代码

```python3
class LargerNumKey(str):
    def __lt__(x, y):
        return x+y < y+x

class Solution:
    def largestNumber(self, nums):
        largest_num = ''.join(sorted(map(str, nums), key=LargerNumKey,reverse = True))
        return '0' if largest_num[0] == '0' else largest_num
```