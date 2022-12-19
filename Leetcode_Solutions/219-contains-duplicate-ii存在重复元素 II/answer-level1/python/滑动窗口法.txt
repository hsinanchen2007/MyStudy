### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        """
        思路：结合滑动窗口的方法。其实要找到两个元素使得 nums [i] = nums [j]，
        并且 i 和 j 的差的绝对值至多为 k，可以理解为在一个窗口为k的子序列中去找这
        两个元素（因为在该窗口中，一定满足 |j-i| <= k的）
        """
        if not nums:
            return False
        record = set() # 窗口
        for i in range(len(nums)):
            if nums[i] in record: # 如果找到 nums [i] = nums [j]
                return True
            record.add(nums[i]) # 没有找到则将当前的元素 nums [i] 放入窗口集合中
            if len(record) == k + 1: # 如果窗口集合的长度大于k，则移除最早放入窗口中的那个元素，保持窗口长度为k
                record.remove(nums[i-k])
        return False
```