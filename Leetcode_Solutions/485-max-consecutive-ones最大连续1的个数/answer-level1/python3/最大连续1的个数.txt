### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        # 自己的方法，有点傻，一旦出现连续n个的1，会把这个连续的数量从1到n都加入到列表里
        # if len(nums) < 2:
        #     if 1 in nums:
        #         return 1
        #     else:
        #         return 0
        # con = []
        # countOne = 0
        # for i in range(len(nums)):
        #     if nums[i] == 1:
        #         countOne += 1
        #         con.append(countOne)   # 一旦出现连续n个的1，会把这个连续的数量从1到n都加入到列表里
        #     else:
        #         con.append(countOne)
        #         countOne = 0
        # return max(con)

        # 原作者：LeetCode
        count = max_count = 0
        for num in nums:
            if num == 1:
                count += 1
            else:
                max_count = max(max_count, count)  # 此方法只存一次最大值，一旦出现更多连续，就会直接替换
                count = 0
        return max(max_count, count)


```