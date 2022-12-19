### 解题思路
把问题分割为 解码nums前2个元素 + 解码后面的元素，使用递归解决。使用try跳过nums[2:]不存在的情况。

### 代码

```python3
class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        res = nums[0] * [nums[1]]
        try:
            res.extend(self.decompressRLElist(nums[2:]))
        except:
            pass
        return res

```