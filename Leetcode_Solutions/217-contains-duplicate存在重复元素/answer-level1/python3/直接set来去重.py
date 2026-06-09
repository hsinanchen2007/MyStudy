### 解题思路
判断先后的长度就行

### 代码

```python3
class Solution:
    def containsDuplicate(self, nums):
        # 这个就是判断数组存在不存在重复元素
        # 感觉直接一个去重来判断长度就行了
        length = len(nums)
        length1 = len(list(set(nums)))
        if length1 == length:
            return False
        else:
            return True
```