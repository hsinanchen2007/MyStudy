
- 时间复杂度: O(N^2)
- 空间复杂度: O(N^2)

根据直线的斜率，我们可以对points做两次遍历，算出这个点与其他所有点组成直线的slope，注意，points里面可能有重复的点

- 第一步, 对于第一个点，我们求出它和其他所有点组成直线的slope，如果它和另外一个点其实是同一个点，那么就记录'same point'，
如果他们组成的直线与x轴平行，就记录'x_parallel', 对于其他所有点，重复第一个点的操作
- 第二步，我们从lookup中的value中找到出现次数最多的那个slope，注意一些corner case，比如slope 就是 'same point'，
那么我们就不需要加上这些相同的点了，否则我们要加上坐标相同的点的个数，同时不停更新res即可
- 注意，最后我们需要返回的是res + 1， 因为我们算的是和某个点p组成直线的slope相同的点，res里面其实是没有算上点p本身的

beats 68.88%


```python
class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        if len(points) <= 1:
            return len(points)
                
        lookup = collections.defaultdict(list)
        for i in range(len(points)):
            for j in range(len(points)):
                if j == i:
                    continue
                x_diff = points[j][1] - points[i][1]
                y_diff = points[j][0] - points[i][0]
                if x_diff == 0:
                    if y_diff == 0:
                        lookup[i].append('same point')
                    else:
                        lookup[i].append('x_parallel')
                else:
                    lookup[i].append(y_diff/x_diff)
                    
        res = -sys.maxsize
        for k, v in lookup.items():
            slope, amount = collections.Counter(v).most_common(1)[0]
            if slope != 'same point':
                amount += v.count('same point')
            res = max(res, amount)
        return res + 1
```