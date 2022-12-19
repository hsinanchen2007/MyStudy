
## 思路：

思路一：暴力

时间复杂度：$O(n^2)$（超时）

无空间

```python
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[i] == nums[j]:
                    return True
        return False
```

思路二：排序

时间复杂度：$O(nlog(n))$

无空间

```python
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        if not nums: return False
        nums.sort()
        for i in range(1, len(nums)):
            if nums[i - 1] == nums[i]: return True
        return False
```

思路三：哈希

用字典记录以及访问的元素

时间复杂度：$O(n)$

空间复杂度：$O(n)$

```python
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        visited = set()
        for num in nums:
            if num in visited:return True
            visited.add(num)
        return False
```

