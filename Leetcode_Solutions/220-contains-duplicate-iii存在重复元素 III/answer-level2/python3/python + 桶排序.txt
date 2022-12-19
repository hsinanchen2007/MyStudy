### 解题思路
桶排序空间换时间
```python
class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], k: int, t: int) -> bool:
        # max(nums[i] - nums[j])
        # abs(i - j) <= k
        # [0, 3,1], k = 1, t = 3
        if nums == [] or t < 0 : return False
        bucket_arr = {} 
        for i, num in enumerate(nums):
            index = num // (t + 1)
            if index in bucket_arr and abs(i - bucket_arr[index]) <= k: return True
            if index - 1 in bucket_arr and  i - bucket_arr[index - 1] <= k and abs(num - nums[bucket_arr[index - 1]]) <= t: return True
            if index + 1 in bucket_arr  and i - bucket_arr[index + 1] <= k and abs(num - nums[bucket_arr[index + 1]] ) <= t: return True
            bucket_arr[index] = i
        return False
```