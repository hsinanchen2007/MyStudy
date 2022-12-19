### 解题思路
1、先对list排序；
2、遍历排序后的list，遇到相同的数即返回True；遍历时未返回True则最后返回False。

### 代码

```python3
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        new_nums = sorted(nums)
        for i in range(len(new_nums)):
            if i > 0:
                if new_nums[i] == new_nums[i-1]:
                    return True
        return False
```