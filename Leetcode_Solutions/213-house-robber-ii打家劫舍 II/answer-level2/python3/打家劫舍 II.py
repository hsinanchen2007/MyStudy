### 解题思路
1）既然抢了第一间就不能抢最后一间；抢最后一间，就不能抢第一间；那么，我们就直接分打劫的方案就好
2）方案一：不抢第一间;方案二：不抢最后一间；
4）两种方案，余下的房子用[《打家劫舍I》](https://leetcode-cn.com/problems/house-robber/)的办法，循环，取相邻两间房子的金额最大值累计就可以了
6）最后，比较方案一和方案二的累计金额，取最大值即可

### 代码

```python
class Solution:
    def rob(self, nums: list) -> int:
        n = len(nums)
        if n == 0:
            return 0
        elif n <= 3:
            return max(nums)

        # 方案一：不抢第一间房子；将第一间房子的金额设置为0，逛到第二间房子的时候，抢到的的累计金额为 nums[1]
        a, b = 0, nums[1]
        # 方案二：不抢最后一间房子；，逛到第二间房子的时候抢到的累计金额有为 max(nums[0], nums[1])
        c, d = nums[0], max(nums[0], nums[1])
        for i in range(3, n+1):
            # 方案一累加
            g = max(a+nums[i-1], b)
            # 方案二：不抢最后一间房子
            if i == n:
                nums[i-1] = 0
            # 方案二累加
            h = max(c+nums[i-1], d)
            # 更新累计金额
            a, b = b, g
            c, d = d, h
        return max(g, h)
```