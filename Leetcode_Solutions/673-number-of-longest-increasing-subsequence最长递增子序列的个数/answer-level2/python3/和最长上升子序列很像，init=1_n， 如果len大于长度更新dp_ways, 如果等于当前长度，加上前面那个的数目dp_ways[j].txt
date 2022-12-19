### 解题思路
和最长上升子序列很像，init=1*n， 如果len大于长度更新dp_ways, 如果等于当前长度，加上前面那个的数目dp_ways[j]

### 代码
if nums[i]>nums[j]:              
    if dp_len[j]+1 > dp_len[i]:
        dp_len[i] = dp_len[j]+1
        dp_way[i] = dp_way[j]
        # max_len = dp_len[i]
        max_len = max(max_len, dp_len[i])
    elif dp_len[j] + 1 == dp_len[i]:
        dp_way[i] += dp_way[j]
```python3
class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:

        # x x x x j x x i
        if not nums:
            return 0
        n = len(nums)
        dp_len = [1]*n
        dp_way = [1]*n
        res = 0
        max_len = 1
        
        for i in range(n):
            for j in range(i):
                if nums[i]>nums[j]:
                    
                    if dp_len[j]+1 > dp_len[i]:
                        dp_len[i] = dp_len[j]+1
                        dp_way[i] = dp_way[j]
                        # max_len = dp_len[i]
                        max_len = max(max_len, dp_len[i])
                    elif dp_len[j] + 1 == dp_len[i]:
                        dp_way[i] += dp_way[j]
        return sum(c for i, c in enumerate(dp_way) if dp_len[i] == max_len)
            
        # res = sum(res + dp_way[i] for i in range(n) if dp_len[i] == max_len)
        # for i in range(n):
        #     if dp_len[i]==max_len:
        #         res+=dp_way[i]
        # return res
        # return sum(c for i, c in enumerate(dp_way) if dp_len[i] == max_len)

```