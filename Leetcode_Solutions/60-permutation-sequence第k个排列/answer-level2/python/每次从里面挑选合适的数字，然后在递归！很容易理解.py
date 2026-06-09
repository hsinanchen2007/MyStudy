### 解题思路
比如果 123的全部排列中，要挑选第3个 ，那么第一个开始的元素就是1

### 代码

```python3

class Solution:
    def __init__(self):
        self.answer = []

    def getPermutation(self, n: int, k: int) -> str:
        # 肯定就不能算出全部的序列吧
        if n < 0 or k < 0:
            return ''
        if k == 1:
            nums = [str(i) for i in range(1, n + 1)]
            return ''.join(nums)
        nums = [i for i in range(1, n + 1)]
        self.dfs(nums, k)
        return ''.join(list(map(str, self.answer)))

    def dfs(self, nums: List[int], k: int):
        if k < 1:
            return
        if len(nums) <= 1:
            self.answer.append(nums[0])
            return nums
        # 这里面的k是从1 开始的
        total_count = self.stage_multiply(len(nums))
        single = total_count // len(nums)
        stage = (k - 1) // single
        # nums是前面传递过来的nums 选择pop掉的元素
        self.answer.append(nums.pop(stage))
        pre = single * stage
        k = k - pre
        self.dfs(nums, k)

    def stage_multiply(self, n: int):
        if n == 1:
            return 1
        return n * self.stage_multiply(n - 1)

```