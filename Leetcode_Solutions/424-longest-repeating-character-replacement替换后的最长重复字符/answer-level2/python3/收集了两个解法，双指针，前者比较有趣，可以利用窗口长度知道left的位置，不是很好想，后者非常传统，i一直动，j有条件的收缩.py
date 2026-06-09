### 解题思路
收集了两个解法，双指针，前者比较有趣，可以利用窗口长度知道left的位置，不是很好想，
后者非常传统，i一直动，j有条件的收缩

### 代码

```python3
# class Solution:
#     def characterReplacement(self, s: str, k: int) -> int:

#         res = 0
#         dic = collections.Counter()
#         max_len = 0

#         for i in range(len(s)):
#             dic[s[i]] += 1
#             max_len = max(max_len, dic[s[i]])

#             if res - max_len < k:
#                 res += 1
#             else:
#                 dic[s[i-res]] -= 1
#         return res


#     from collections import defaultdict
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        # 滑动窗口
        if s is None or len(s) == 0:
            return 0
        hash = collections.defaultdict(int)
        n = len(s)
        left = 0
        maxCount = 0
        res = 0
        for right in range(n):
            hash[s[right]] += 1
            # 当前窗口中元素最多的字符的数量
            maxCount = max(maxCount, hash[s[right]])
            # 注意这里为什么是while循环，举个特列 AABCD K=1,左指针必须移动到条件r-l+1不大于K
            while right - left + 1 - maxCount > k:
                hash[s[left]] -= 1
                left += 1
                # 这里按理也需要判断一下maxCount,为什么不判断了呢，相当于maxCount只大不小？
                # 这是由于我们只找满足条件的最大值，当大于maxcount的值出现，表示right-left+1的值更大!
            res = max(right - left + 1, res)
        return res

```