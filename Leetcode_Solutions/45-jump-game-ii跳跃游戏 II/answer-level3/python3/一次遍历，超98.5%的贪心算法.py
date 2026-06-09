两个指针cur、k：
1. cur用以从左遍历数组（一次跳两格个两次跳一个是一样的，所以cur每次+1）
2. k用以记录此跳能够到达的最远距离，当cur==k时，说明需要进入下一跳

结束条件是：当此次跳跃达到或者超过数组左边界
此时k有两种情况：
![微信图片_20190921110021.jpg](https://pic.leetcode-cn.com/a3efe748cec54e666d6983d1b1e752e31d0efbcaf0bb357b1dab2cd095bd5199-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20190921110021.jpg)

```
class Solution(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 1:
            return 0
        cur = 0
        max_jump = 0
        k = nums[0]
        tm = 1
        while cur <= max_jump:
            max_jump = max(cur+nums[cur], max_jump)
            # 当指针指到k，说明这一跳已经达到最大范围，进入下一跳
            if cur == k:
                k = max_jump
                tm += 1
            cur += 1
            # 最大距离超过了，直接结束
            if max_jump >= len(nums)-1:
                # 这里分两种情况：
                # 1.当k当等于或者超出了数组， cur所在的这一跳已经包含了，直接renturn
                if k >= len(nums)-1:
                    return tm
                # 2.当k在数组内部，那么从cur到最后必定越过k，需要再来一跳
                else:
                    return tm + 1
```
