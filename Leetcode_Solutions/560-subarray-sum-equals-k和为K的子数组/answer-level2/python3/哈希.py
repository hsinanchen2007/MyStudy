### 解题思路
python的缺点是性能，暴力解决不了这道题，需要用hash。

### 代码

```python3
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        # count = 0
        # for i in range(len(nums)):
        #     sum = 0
        #     for j in range(i,len(nums)):
        #         sum += nums[j]
        #         if sum == k:
        #             count += 1
        # return count

        count, sumnums = 0, 0
        hash_tbl = {0:1}
        for i in range(len(nums)):
            sumnums += nums[i]
            count += hash_tbl.get(sumnums-k, 0)
            if sumnums in hash_tbl:
                hash_tbl[sumnums] += 1
            else:
                hash_tbl[sumnums] = 1
        return count

```