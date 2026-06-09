### 解题思路

![搜狗截图20191222130438.png](https://pic.leetcode-cn.com/6205d999252e5c5436c3578e104621d38b2349f0f59417c202810bffe9b5b8a6-%E6%90%9C%E7%8B%97%E6%88%AA%E5%9B%BE20191222130438.png)

集合+字典法
用集合记录可能的数字
用字典存储每个数字出现的次数

### 代码

```python
class Solution(object):
    def isPossibleDivide(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """

        n = len(nums)
        if n % k != 0:
            return False

        # 用集合记录可能的数字
        s = set(nums)
        minList = list(s)
        minList.sort()

        # 用字典存储每个数字出现的次数
        d = dict()
        for num in nums:
            if num not in d:
                d[num] = 0
            d[num] += 1

        # 判断每组是否可由k个连续数字构成
        m = n // k  # m组
        start = 0  # 起始位置
        for mi in range(m):
            if start >= len(minList):
                return False
            minv = minList[start]
            flag = True
            tmpstart = start
            for key in range(minv, minv + k):
                if key not in d:
                    return False
                if d[key] < 1:
                    return False
                elif d[key] == 1:
                    d[key] -= 1
                    tmpstart += 1
                elif d[key] > 1:
                    d[key] -= 1
                    if flag:
                        start = tmpstart
                        flag = False
            if flag:
                start = tmpstart

        return True
```