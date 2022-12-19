### 解题思路
因为数据范围在1~n, 所以可以O(1)空间把自己本身作为哈希
通过交换元素使得每个index的值对应为index+1. 
同时注意python的这种交换方式 a, b = b, a 是有顺序的, 前面的比后面的先改变
所以要当心 a, nums[a] = nums[a], a的这种情况

### 代码

```python3
class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        i, l = 0, len(nums)
        copy = lose = 0
        while i<l:
            if nums[i]!=i+1:
                if nums[nums[i]-1]!=nums[i]:
                    # 不能这样交换! 一定要保证nums[i]最后再改变!
                    # nums[i], nums[nums[i]-1] = nums[nums[i]-1], nums[i] 
                    nums[nums[i]-1], nums[i] = nums[i], nums[nums[i]-1]
                    # 或
                    # tmp = nums[nums[i]-1]
                    # nums[nums[i]-1] = nums[i]
                    # nums[i] = tmp
                else:
                    copy = nums[i]
                    i += 1
            else: i += 1
        for i in range(l):
            if nums[i]==copy:
                if nums[i]!=i+1: return [copy, i+1]

```