# 解题思路
1. 在纸上画了画，因为题目要求O（N），就开始想着如何遍历一边搞定
2. 发现每次如果当前是降序而之前是升序，那么加1. 反之亦然
3. 其他边界case：第一次也就是nums[1]-nums[0]，开头并不需要判断之前是否升降。

写完，修改了三次边界case 的bug外，发现竟然通过了。（但是我还是不怎么理解这个解法为何是贪心算法）

```python []
class Solution(object):
    def wiggleMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ret = 0
        l = len(nums)
        if not nums:
            return ret
        prev_flag = 0
        for i in range(1, l):
            flag = nums[i] - nums[i-1]
            if (i == 1 and flag != 0):
                prev_flag = flag
                ret += 1
            elif (flag > 0 and prev_flag <= 0) or (flag < 0 and prev_flag >= 0):
                prev_flag = flag
                ret += 1
        return ret+1
```

