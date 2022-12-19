### 思路

##### 解法一

**哈希表**

```
遍历数组，未出现过的标记 flag 为 True，已出现过就返回该值。
```

**时间复杂度:** O(n)，n 为 nums 的长度。
**空间复杂度:** O(n)，n 为 nums 的长度。

##### Python3代码

```python
from typing import List

class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        # solution one: 哈希表
        n = len(nums)
        flag = [False for i in range(n)]
        for i in range(n):
            if flag[nums[i]] == False:
                flag[nums[i]] = True
            else:
                return nums[i]
        return -1
```

##### 解法二

**排序**

```
先对数组排序，然后遍历，和前一个数相同就返回该值。
```

**时间复杂度:** O(n)，n 为 nums 的长度。
**空间复杂度:** O(1)

##### Python3代码

```python
from typing import List

class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        # solution two: 排序
        nums.sort()
        pre = nums[0]
        for i in range(1, len(nums)):
            if pre == nums[i]:
                return nums[i]
            else:
                pre = nums[i]
        return -1
```

##### 解法三

**两个萝卜一个坑**

```
遍历数组：
1. 如果该位置的值和该下标一致，不管他
2. 如果以该位置值为下标的值和该位置值相同，表示有重复，则返回该值
3. 否则，交换以该位置值为下标的值和该位置值
```

**时间复杂度:** O(n)，n 为 nums 的长度。
**空间复杂度:** O(1)

##### Python3代码

```python
from typing import List

class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        # solution three
        n = len(nums)
        for i in range(n):
            if nums[i] == i:
                continue
            # 有重复
            elif nums[nums[i]] == nums[i]:
                return nums[i]
            # 交换
            else:
                nums[nums[i]], nums[i] = nums[i], nums[nums[i]]
        return -1
```

### 代码地址

[GitHub链接](https://github.com/Wonz5130/LeetCode-Solutions/blob/master/solutions/Interview-03-shu-zu-zhong-zhong-fu-de-shu-zi-lcof/03.py)