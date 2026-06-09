### 解题思路
此处撰写解题思路
暴力解法：
创建一个为-1的列表。遍历列表中的每个元素，然后对他之后的元素依次进行对比，如果有大于当前元素的，记录下来。最后返回创建的列表
### 代码

```python3
class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        res = [-1]*len(nums)
        l = len(nums)
        for i in range(l):
            for j in range(i+1,l+i+1):
                if nums[j%l] > nums[i]:
                    res[i] = nums[j%l]
                    break
        return res


```