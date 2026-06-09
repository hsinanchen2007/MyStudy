### 解题思路
求出每一层的缝隙位置，建一个字典，用砖的层数减去每个位置的缝隙数，求一个最小值即可。

![UC截图20200116160140.png](https://pic.leetcode-cn.com/9177026c1741def716a7a97ae09e17974bfccb7199643627e1cb506eff65ed98-UC%E6%88%AA%E5%9B%BE20200116160140.png)


### 代码

```python3
class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:
        import collections
        n = len(wall)
        res = []
        for zhuanqiang in wall:
            if len(zhuanqiang) == 1:
                continue
            sum = 0
            for i in range(0,len(zhuanqiang)-1):
                sum = zhuanqiang[i] = sum + zhuanqiang[i]
                res.append(sum)
        d = dict(collections.Counter(res))
        ans = len(wall)
        for i in d:
            ans = min(ans,n - d[i])
        return ans
```