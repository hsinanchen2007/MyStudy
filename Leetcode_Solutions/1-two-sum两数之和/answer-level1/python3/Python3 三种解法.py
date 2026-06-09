解法一：暴力循环
```python
    def two_sum(nums: List[int], target: int) -> List[int]:
        size = len(nums)
        for i, m in enumerate(nums):
            j = i + 1
            while j < size:
                if target == (m + nums[j]):
                    return [i, j]
                else:
                    # print(i, j, m + _n, " didn't match!")
                    j += 1
```
对于给定的target，遍历数组 时间复杂度O(n)， 查找target == m+ n的元素，时间复杂度 O(n)
因为时间复杂度为 O（n^2）
遍历过程，未使用数据结构存储，故空间复杂度为O(1)
耗时 60ms	

解法二：字典模拟Hash
```python
    def tow_sum_with_dict(nums: List[int], target: int) -> List[int]:
        _dict = {}
        for i, m in enumerate(nums):
            _dict[m] = i

        for i, m in enumerate(nums):
            j = _dict.get(target - m)
            if j is not None and i != j:
                return [i, j]
```
时间复杂度为O（n）
空间复杂度为O（n）
执行时间 52 ms	

解法三：一遍字典模拟Hash
```python
    def tow_sum_with_dict2(nums: List[int], target: int) -> List[int]:
        _dict = {}
        for i, m in enumerate(nums):
            if _dict.get(target - m) is not None:
                return [i, _dict.get(target - m)]
            _dict[m] = i
```
时间复杂度为O（n）
空间复杂度为O（n）
执行时间 46 ms	

