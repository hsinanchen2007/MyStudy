
```
def _missingNumber(self, nums: List[int]) -> int:    # 基础解法
        l = len(nums)+1     # 主要是这点要认清楚
        for i in range(l+1):
            if i not in nums:   # 这里可能比较耗时，因为不是哈希list
                return i
    def __missingNumber(self, nums: List[int]) -> int:     # 哈希集合方法，如果是list会很慢
        l = len(nums)+1     # 主要是这点要认清楚
        hash_set = set()
        for i in nums:
            if i not in hash_set:
                hash_set.add(i)
        for i in range(l+1):
            if i not in hash_set:   # 这里可能比较耗时，因为不是哈希list
                return i
    def missingNumber(self, nums: List[int]) -> int:    # 高级写法 | 异或 | 异或满足结合律
        missing = len(nums)
        for i, num in enumerate(nums):
            missing ^= i ^ num
        return missing
```
异或满足结合律，谁又能想到
