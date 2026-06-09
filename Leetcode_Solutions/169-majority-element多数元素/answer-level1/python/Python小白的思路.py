### 解题思路
先统计出每个元素出现的次数
然后，再判断该元素出现的次数是否大于 ⌊ n/2 ⌋


### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        numsDict = {} # 统计列表中出现的元素的次数，key:元素，value:次数
        for i in nums:
            if i not in numsDict:
                numsDict[i] = 1
            else:
                numsDict[i] += 1

        for j in numsDict:
            if numsDict[j] > (len(nums) // 2):
                return j
                break
            else:
                continue
```