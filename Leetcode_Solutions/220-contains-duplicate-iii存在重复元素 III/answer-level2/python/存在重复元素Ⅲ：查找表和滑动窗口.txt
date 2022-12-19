#### 思路
维护一个长度最大为k的滑动窗口，遍历`nums`数组`nums[i]`，判断窗口内的差的绝对值是否小于t。
#### 代码
```python []
class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], k: int, t: int) -> bool:
        n = len(nums)
        if n <= 1:
            return False
        
        record = set()  # 定义窗口
        for i in range(n):
            if t == 0:  # 如果t=0，那么看看窗口内是否有重复元素，有就返回True
                if nums[i] in record:
                    return True
            else:
                for j in record:  # 遍历窗口元素，判断是否有绝对值小于t的情况，有就返回True
                    if abs(j - nums[i]) <= t:
                        return True
            record.add(nums[i])  # 向集合添加元素
            
            if len(record) > k:
                record.remove(nums[i-k])  # 维护长度为k的窗口
        return False
```
![白色背景关注.jpg](https://pic.leetcode-cn.com/47d1b5430e869ed420bb0c6e8a90250773528ccf1bf6d4d43aef80dd326eeef9-%E7%99%BD%E8%89%B2%E8%83%8C%E6%99%AF%E5%85%B3%E6%B3%A8.jpg)
