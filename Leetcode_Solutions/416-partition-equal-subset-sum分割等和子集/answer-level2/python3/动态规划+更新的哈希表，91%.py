
### 代码

```python3
class Solution:
    # def canPartition(self, nums: List[int]) -> bool:
    def canPartition(self, nums):
        nums.sort(reverse = True)
        s = sum(nums)
        if not nums or s % 2 == 1:
            return False
        dic = {0:1}class Solution:
    # def canPartition(self, nums: List[int]) -> bool:
    # 本质仍是动态规划下的遍历搜索问题，每次搜索列表中是否有target，没有则搜索(target - 列表中的元素)，类似于L638大礼包问题
    def canPartition(self, nums):
        nums.sort(reverse = True)
        s = sum(nums)
        # 剪枝
        if not nums or s % 2 == 1:
            return False
        dic = {}
        # 将列表元素存入字典中，**组合后**列表元素：个数(经过函数迭代列表会进行组合，因此列表元素组成会改变但总和不变)
        for i in nums:
            dic[i] = 1 if i not in dic else dic[i] + 1
        s = s / 2
        if nums[0] > s:
            return False
        return self.search(nums, dic, s)
    def search(self, nums, dic, s):
        # 判决条件：列表经过组合后存在该元素并且个数不为零
        if s in dic and dic[s]>0:
            return True
        for i in range(len(nums)):
            if s - nums[i] < 0: continue
            dic[nums[i]] -= 1
            # 由于nums[i]属于组合后的列表nums,同样组合后的dic等价于nums，因此必然存在nums[i]
            # if dic[nums[i]] > 0 and self.search(nums[i+1:], dic, s-nums[i]):
            # 将重新组合后的dic和nums以及新的搜索目标传入函数迭代
            if self.search(nums[i+1:], dic, s-nums[i]):
                return True
            # dfs,修改回来继续同层搜索
            dic[nums[i]] += 1
        return False
        for i in nums:
            dic[i] = 1 if i not in dic else dic[i] + 1
        s = s / 2
        if nums[0] > s:
            return False
        return self.search(nums, dic, s)
    def search(self, nums, dic, s):
        if s in dic and dic[s]>0:
            return True
        for i in range(len(nums)):
            if s - nums[i] < 0: continue
            dic[nums[i]] -= 1
            # if dic[nums[i]] > 0 and self.search(nums[i+1:], dic, s-nums[i]):
            if self.search(nums[i+1:], dic, s-nums[i]):
                return True
            dic[nums[i]] += 1
        return False
```