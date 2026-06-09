### 解题思路
1. 暴力法+二分
    在求每一个i对应的和的时候, 可利用数据公式n*(a1+an)/2。因为是有顺序的, 可利用二分法快速找到
2. 滑动窗口
    当窗口内小于target时,向右移动窗口。从>=target的结果中选取=target的合法值
### 代码

```python
class Solution(object):
    def findContinuousSequence(self, target):
        """
        :type target: int
        :rtype: List[List[int]]
        """
        # 遍历+二分
        # end = target / 2 + 1
        # res = []
        # for ii in range(1, end):
        #     i = ii + 1
        #     j = end + 1
        #     while i <= j:
        #         mid = i + (j - i) / 2
        #         s = (mid - ii + 1) * (ii + mid) / 2
        #         if s == target:
        #             res.append(range(ii, mid + 1))
        #             break
        #         elif s > target:
        #             j = mid - 1
        #         else:
        #             i = mid + 1
        # return res

        # 滑动窗口
        i, j, s, end = 1, 1, 0, target / 2 + 2
        res = []
        while j < end:
            s += j
            j += 1
            while s >= target:
                if s == target and j - i > 1:   # 至少含有两个数, j是滑动窗口右边界+1
                    res.append(range(i, j))
                s -= i
                i += 1
        return res
```