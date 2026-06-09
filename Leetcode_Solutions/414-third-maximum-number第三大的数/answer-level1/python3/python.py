### 解题思路
去重，降序，取值

### 代码

```python3
class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        # 去重，降序
        nums = sorted(list(set(nums)),reverse=True)
        # 第三位存在就取第三位，不存在取第一位
        # 对于列表中不存在的位置，切片读取返回空，索引取值会报错
        return nums[2] if nums[2:3] else nums[0]
```