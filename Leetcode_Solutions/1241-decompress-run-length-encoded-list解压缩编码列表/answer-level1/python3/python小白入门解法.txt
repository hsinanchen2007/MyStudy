### 解题思路
执行用时 :40 ms, 在所有 Python3 提交中击败了91.04%的用户
内存消耗 :13.4 MB, 在所有 Python3 提交中击败了100.00%的用户

核心思路是取list中的前两个元素，根据这两个元素来来确定解压后的list，然后删除这两个元素，直到原nums list为空。

### 代码

```python3
class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        result = []
        while len(nums) != 0:
            for i in range(nums[0]):
                result.append(nums[1])
            del nums[:2]
        return result
```