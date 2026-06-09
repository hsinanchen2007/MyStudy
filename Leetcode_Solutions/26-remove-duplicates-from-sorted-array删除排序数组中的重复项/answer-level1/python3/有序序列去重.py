### 解题思路
思路很简单，一直与后一个元素比较，发现重复即删除。执行慢应该主要是remove那里，直接索引拼接可能好点

### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            try:
                while nums[i] == nums[i+1]:
                    nums.remove(nums[i])
            except Exception as e:
                print("index 超出！")
                return len(nums)
```

### remove 改用 pop后性能显著提升

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            try:
                while nums[i] == nums[i+1]:
                    nums.pop(i)
            except Exception as e:
                print("index 超出！")
                return len(nums)
```
68ms 14M 左右


