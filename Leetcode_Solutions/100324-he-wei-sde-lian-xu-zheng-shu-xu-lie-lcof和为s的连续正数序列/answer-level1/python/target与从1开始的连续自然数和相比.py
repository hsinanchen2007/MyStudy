![image.png](https://pic.leetcode-cn.com/46e929351e4807b6cd94854265c31ae561cd37442ac1d2d6b648eacf95561814-image.png)


class Solution(object):
    def findContinuousSequence(self, target):

        if target <= 1:
            return []
        res = []
        m = int((2 * target) ** 0.5)
        if target - m * (m + 1) / 2 < 0:
            m -= 1
        for i in range(m, 1, -1):
            temp = i * (i + 1) / 2
            sub = target - temp
            if sub % i == 0:
                r = sub / i
                res.append([j + r + 1 for j in range(i)])
        return res