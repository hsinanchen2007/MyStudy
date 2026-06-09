### 解题思路
动态规划的记忆机制

### 代码

```python3
class Solution:
    def massage(self, nums) -> int:
        # 这显然是个贪心算法，动态规划的求解问题 约等于最长路径？
        # 预约某一天后，只有两个选择，后天及之后的max选择，大后天及之后的max选择
        self.nums = nums
        self.size =len(nums)
        self.memory = dict()
        begin = 0
        if self.size ==0:
            return 0
        else:
            return self.max_child_nums(begin)
        # 递归的中止条件是空数组，单元素数组，双元素数组
    def max_child_nums(self, i):
        # size = len(nums)
        if i == self.size -1:
            self.memory[i] = self.nums[i]
            return self.nums[i]
        elif i == self.size -2:
            tmp_max = max(self.nums[i:])
            self.memory[i] = tmp_max
            return tmp_max
        elif i>=self.size:
            return 0
        else:
            if i in self.memory.keys():
                return self.memory[i]
            else :
                max_0 = self.nums[i] + self.max_child_nums(i+2)
                max_1 = self.nums[i+1] + self.max_child_nums(i+3)
                max_val = max(max_0, max_1)
                self.memory[i] = max_val
            # print(max_val)
            return max_val
```