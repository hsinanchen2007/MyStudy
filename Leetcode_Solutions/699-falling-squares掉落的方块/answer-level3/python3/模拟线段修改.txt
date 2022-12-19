直接遍历查找目标区间了，也能正常AC，如果覆盖区间用二分查找，区间最高高度用线段树记录，肯定能更快些，太麻烦这里就不写了，这个属于朴素的O(n^2)算法。

![image.png](https://pic.leetcode-cn.com/d5a0d67964f919a50d859ba102eb33aecaaf30af3dfa68850b2912cf3edc4d1a-image.png)

```
class Solution:
    def fallingSquares(self, positions: List[List[int]]) -> List[int]:
        d = [[-float('inf'), float('inf'), 0]]      #线段初始化，就是负无穷到正无穷高度为0的区间
        ans = [0]       #递增的输出，所以搞个[0]来初始化
        for l, h in positions:
            r = l + h
            i = 0
            while d[i][1] <= l:     #查找覆盖区间左端
                i += 1
            j = len(d) - 1
            while d[j][0] >= r:     #查找覆盖区间右端
                j -= 1
            hmax = max(d[k][2] for k in range(i, j + 1)) + h        #查找区间内最高高度
            ans += [max(ans[-1], hmax)]     #写入输出
            d = d[:i] + ([[d[i][0], l, d[i][2]]] if d[i][0] < l else []) + [[l, r, hmax]] + ([[r, d[j][1], d[j][2]]] if r < d[j][1] else []) + d[j + 1:]
            #修改线段
        return ans[1:]
```
