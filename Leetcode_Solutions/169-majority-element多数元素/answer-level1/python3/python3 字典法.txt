### 解题思路
采用字典法统计列表每个元素的出现次数，但凡元素的出现次数超过n/2，就跳出循环输出该元素。

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        record={}
        n=len(nums)
        for i in range(n):
            record.setdefault(nums[i],0)
            record[nums[i]]+=1
            if record[nums[i]]>n//2:
                break
        return nums[i]
        

```