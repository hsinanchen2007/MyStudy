### 解题思路
all函数和index函数的运用。

### 代码

```python3
class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        return nums.index(max(nums)) if all([max(nums)>=2*num for num in nums if num != max(nums)]) else -1
```
最后，低调推荐个人公众号：[小数志](https://pic.leetcode-cn.com/962ebbb357f15acd99bfcc5dc74188fc9f2a3492e73bca90b673428d5c1c7559-image.png)