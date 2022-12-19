### 解题思路
想法很简单，但是处理各种边界状态断断续续搞了两天。

中心思想就是将所有的建筑折成两个端点，每一个端点是一个三元组，`(x, left/right end, height)`， 依次是该点在 `X` 轴上的坐标，是左端点还是右端点，高度。左右端点分别用 $0,1$ 表示，之所以放在中间，是希望在排序是优先于高度。

然后我们遍历这个端点数组。如果当前是左端点且高度大于高度数组中的最大值，就在结果数组中插入轮廓点，如果小于则跳过，再将当前高度插入高度数组；如果是右端点，且高度等于高度数组中的最大值，则从高度数组中去掉该高度，并用第二高度在结果数组中插入轮廓点。

其他复杂的地方就是处理端点重叠的情况。这里引入了一个 `pre_p` 变量记录上一个点方便处理。

### 代码

```python3
import bisect

class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        points = []
        for l,r,h in buildings:
            points.append((l,0,h))
            points.append((r,1,h))
        points = sorted(points)
        hs, res, pre_p = [0], [], (-1,1,0)
        for i,(x,e,h) in enumerate(points) :
            px, pe, ph = pre_p
            if e == 0 : # left end
                if h > hs[-1] :
                    if x == px :
                        if pe == 0 :
                            res[-1][1] = h
                        else :
                            res.append([x,h])
                    else:
                        res.append([x,h])
                    pre_p = points[i]
                bisect.insort(hs, h)
            else : # right end
                if h == hs[-1] and h != hs[-2]:
                    res.append([x,hs[-2]])
                hs.remove(h)
                re_p = points[i]

        return res
```