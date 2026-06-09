### 解题思路
思路很简单。首先确定哈希表中{key: value}存储的是以key为边界的连续序列的另一边界，如果key是左边界，那么value就是右边界，如果key是右边界，那么value就是左边界。举例来说，当前元素是num，需要查看num - 1和num + 1是否出现过，如果将num - 1看做右边界，那么my_dict[num - 1]就是以num - 1为右边界的连续序列的左边界，原因是如果num - 1是左边界，存储的是右边界，那么num一定出现过，出现过的元素直接continue。这样我们就可以对连续的序列的边界进行更新，更新左边界存储的右边界以及右边界存储的左边界，看代码及注释即可。

### 代码

```python
class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        my_dict = {}
        max_len = 0
        for num in nums:
            if num not in my_dict:
                my_dict[num] = num
                left = right = num
                if num - 1 in my_dict: # 合并以num - 1为右边界的连续序列
                    left = my_dict[num - 1] 
                if num + 1 in my_dict: # 合并以num + 1为左边界的连续序列
                    right = my_dict[num + 1]
                my_dict[left] = right # 更新左边界存储的右边界
                my_dict[right] = left # 更新右边界存储的左边界
                if right - left + 1 > max_len:
                    max_len = right - left + 1
        return max_len
```