### 解题思路
Step 1.将数据分成N个2元数据，每隔一个元素向下
Step 2.根据每一对中第一个元素的值，进行遍历，每遍历一次，将res数组中添加一次第二个元素
Step 3.以此类推

### 代码

```python3
class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        L = len(nums)
        res = []
        for i in range(0, L, 2):
            for j in range(nums[i]):
                res.append(nums[i+1])
        return res
```