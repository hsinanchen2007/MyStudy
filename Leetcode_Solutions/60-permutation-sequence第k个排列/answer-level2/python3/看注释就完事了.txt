### 解题思路
全排列的个数是n! 
比如 1 2 3 4。1 开头的有两个 ，2,3,4也是。所以就先判断是哪个数字开头的 然后在查找。就会快一些
超过了5%....

### 代码

```python3

class Solution:
    def __init__(self):
        self.res = []
        self.path = []
        self.k = 1

    def permute(self, nums: List[int], k) -> List[List[int]]:
        self.search(nums)
        return self.res[k - 1]

    def search(self, nums: List[int]):
        if len(self.path) == len(nums):
            self.res.append(self.path[:])
            return
        for i in range(len(nums)):
            if nums[i] not in self.path:
                self.path.append(nums[i])
                self.search(nums)
                self.path.pop(-1)

    def getPermutation(self, n: int, k: int) -> str:
        # 肯定就不能算出全部的序列吧
        if n < 0 or k < 0:
            return ''
        # k 是第k个
        # 1 2 3 ：1、2、3 开头的有各2 种
        if k == 1:
            nums = [str(i) for i in range(1, n + 1)]
            return ''.join(nums)

        total_count = self.stage_multiply(n)
        single = total_count // n
        stage = (k - 1) // single
        nums = [i for i in range(1, n + 1)]
        nums.pop(stage)
        # print(nums)
        pre = single * stage
        k = k - pre
        # print(k)
        r = self.permute(nums, k)
        # print(r)
        r.insert(0, stage + 1)
        return ''.join(list(map(str, r)))

    def stage_multiply(self, n: int):
        if n == 1:
            return 1
        return n * self.stage_multiply(n - 1)


```