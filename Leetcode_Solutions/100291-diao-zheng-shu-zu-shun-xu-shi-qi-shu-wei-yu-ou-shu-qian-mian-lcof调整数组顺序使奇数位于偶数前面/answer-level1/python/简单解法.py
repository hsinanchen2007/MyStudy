一起组队刷题打卡，微博 [@爱编程的周鸟](https://weibo.com/iosxxoo) 求关注求交流。
### 解题思路
遍历一次，统计奇数个数。

然后从前往后填坑。

### 代码

```python
class Solution(object):
    def exchange(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        odd_cnt = 0
        res = [0] * len(nums)
        # 统计个数
        for n in nums:  
            if n % 2 != 0:
                odd_cnt += 1
        # 填坑
        odd_i = 0
        even_i = odd_cnt
        for i in range(len(nums)):
            if nums[i] % 2 != 0:  
                res[odd_i] = nums[i]
                odd_i += 1
            else:
                res[even_i] = nums[i]
                even_i += 1
        return res
```