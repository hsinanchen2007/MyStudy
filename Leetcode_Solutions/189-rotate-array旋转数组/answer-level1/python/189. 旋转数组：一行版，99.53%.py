数组切片必须等于切片，这样才是修改值，左边方括号和冒号都是要的

```python []
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        nums[:] = nums[-k%len(nums): ] + nums[: -k%len(nums)]
```

感谢 [@wendall](/u/wendall) 纠错

原版一行98.44%时间,60ms，当时是可以AC，但实际上是错的，现在好像已经AC不了了。

```python []
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        nums[:] = nums[len(nums) - k: ] + nums[: len(nums) - k]
```

![image.png](https://pic.leetcode-cn.com/486bc5a654297df35028f6ba4e6e0adc59f52e2c2260596503109dbe231c1671-image.png)

空间也是$O(1)$的一行版，99.53%

```python []
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        nums[: ] = (nums[i] for i in range(-(k % len(nums)), len(nums) - k % len(nums)))
```
