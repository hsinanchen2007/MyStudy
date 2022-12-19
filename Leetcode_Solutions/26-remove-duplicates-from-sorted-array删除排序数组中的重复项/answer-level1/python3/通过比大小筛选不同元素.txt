### 解题思路
通过在遍历中与前一个已完成比较的元素比较大小，如果不等就将已比较元素的后一个位置赋值为当前元素。（建立在有序列表的基础上，所以新元素的出现只可能在已比较元素的后方）

### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        j = 0
        for i in range(len(nums)):
            if nums[j] < nums[i]:
                j += 1
                nums[j] = nums[i]
        return j + 1
```
### 结果
![image.png](https://pic.leetcode-cn.com/655e51b17cd2a674660b82f0e3086da6611cff7bb1bea176203f45f9ac506c09-image.png)
