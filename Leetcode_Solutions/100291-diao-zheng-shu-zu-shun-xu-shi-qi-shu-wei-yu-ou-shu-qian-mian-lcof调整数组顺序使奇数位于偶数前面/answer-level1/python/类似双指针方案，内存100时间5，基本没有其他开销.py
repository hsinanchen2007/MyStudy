### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
        def exchange(self, nums):
            self.nums = nums

            def get_first_oushu(index):
                for i in range(len(self.nums)-index):
                    if self.nums[i+index] % 2 == 0:
                        return i+index
                return float('inf')

            def get_last_jishu(index):
                for i in range(len(self.nums)-index):
                    if self.nums[len(self.nums) - 1 - i-index] % 2 == 1:
                        return len(self.nums) - 1 - i -index
                return -1
            l_index = 0
            r_index = 0
            while 1:
                l, r = get_first_oushu(l_index), get_last_jishu(r_index)
                l_index= l
                r_index =len(self.nums)-r
                if l <= r:
                    self.nums[l], self.nums[r] = self.nums[r], self.nums[l]
                else:break
            return self.nums
```