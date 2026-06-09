### 解题思路
采用双指针遍历一次，第2个指针总是寻找不等于第一个指针的下一个元素。
![image.png](https://pic.leetcode-cn.com/33f9f5ec67bba30f7151baf0052b4b36d8204d1ab56f892f60a6aa9072585964-image.png)

### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i = 0
        j = i + 1
        nums_len = len(nums)
        while i < nums_len and j < nums_len:
            if nums[j] == nums[i]:
                j += 1
                continue

            nums[i+1] = nums[j]
            j += 1
            i += 1
        
        return i + 1

```