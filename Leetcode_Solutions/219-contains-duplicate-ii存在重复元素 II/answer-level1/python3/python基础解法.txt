### 解题思路
1. 暴利搜索（超时）
2. 利用哈希表进行搜索，类似于two_sum问题

### 代码

```python3
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        # n = len(nums)
        # for i in range(n-1):
        #     for j in range(i+1, n):
        #         if nums[i] == nums[j] and abs(j-i)<= k:
        #             return 1
        #         else:
        #             j += 1

        hashmap={}
        for i in range(len(nums)):
            if nums[i] not in hashmap:
                hashmap[nums[i]]=i
            else:
                if i - hashmap[nums[i]]<= k:
                    return True
                else:
                    hashmap[nums[i]]=i
        return False
```