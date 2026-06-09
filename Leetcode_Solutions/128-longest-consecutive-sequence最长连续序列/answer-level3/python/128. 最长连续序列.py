### 解题思路
- 获取左右边界长度；
- 更新当前长度，有条件更新最大长度；
- 更新当前数字、该数字对应的左右边界长度；
### 代码

```python3
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        dic = dict()
        max_len = 0
        for num in nums:
            if num not in dic:
                left = dic.get(num - 1, 0)
                right = dic.get(num + 1, 0)
                cur_len = left + 1 + right
                if cur_len > max_len:
                    max_len = cur_len
                dic[num] = cur_len
                dic[num - left] = cur_len
                dic[num + right] = cur_len
        return max_len
```