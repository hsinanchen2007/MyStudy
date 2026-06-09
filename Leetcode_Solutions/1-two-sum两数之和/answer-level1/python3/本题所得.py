### 解题思路
此题的一些所得
1.字典的用法，增加键值对 dic[n] = i
2.enumerate（）函数得到列表的下标和值

### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = {}
        for i, n in enumerate(nums):
            if target - n in d:
                return [d[target-n], i]
            d[n] = i

```