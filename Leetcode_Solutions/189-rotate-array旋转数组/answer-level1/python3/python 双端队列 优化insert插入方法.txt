解题思路：
最简单的思路就是，将最后一位`pop`出去，然后`insert`到下标0位置
`pop`操作是O(1)
`insert(0, x)`操作就是O(n)了
为了规避这一问题，可以使用双端队列，pop和insert都是O(1)

python内置模块`colletions`提供的`deque`

代码：
```
import collections
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        b = collections.deque(nums)
        for i in range(k):
            b.insert(0, b.pop())
        nums.clear()
        nums.extend(list(b))
```
不仅如此，`colletions`也提供了
`rotate(n)`
> 将deque向右旋转n 个元素。如果 n 是负数, 则向左旋转.向右旋转1个元素等价于d.appendleft(d.pop()).
所以，也可以这样写
```
import collections
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        b = collections.deque(nums)
        b.rotate(k)
        nums.clear()
        nums.extend(list(b))
```