### 解题思路
* ![combination-sum-iii.png](https://pic.leetcode-cn.com/ad68397135105d4e99c21164105c9a9e9d4056234d93c23c314aaaddfdfb8d98-combination-sum-iii.png)

### 代码

```python
class Solution(object):
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        def rec(idx, j, tmp, ret):
            """
                idx 当前处理了几个数
                j 当前处理的数据的开始
                tmp 过程数据
                ret 最终要返回的结果
            """
            if idx == k:
                if sum(tmp) == n:
                    ret.append(tmp[:])
                return
            if sum(tmp) >= n:
                return
            for i in xrange(j, 10):
                tmp.append(i)
                rec(idx + 1, i + 1, tmp, ret)
                tmp.pop(-1)
        ret = []
        rec(0, 1, [], ret)
        # print ret
        return ret
```