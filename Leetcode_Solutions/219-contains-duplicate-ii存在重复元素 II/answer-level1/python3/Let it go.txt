### 解题思路
一开始就读错题意，以为是==k，结果是 <=k
可能是我语文没过关。唉难受呀马飞。
### 代码
```python
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        dic = dict()
        for i in range(len(nums)):
            if nums[i] not in dic: dic[nums[i]] = i
            elif i - dic[nums[i]] <= k:return True
            else: dic[nums[i]] = i
        return False
```