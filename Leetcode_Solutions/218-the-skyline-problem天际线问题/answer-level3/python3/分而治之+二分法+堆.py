
## 思路：

**思路一**:分而治之[^1]

两两合并，最后一起合并， 所以我们要知道两个不同建筑物如何合并， 如下图所示：

![1566806815085.png](https://pic.leetcode-cn.com/ad2d892fe91f422e8a47f8e0eae54274b94b2d72797b94d6738c61c536def81a-1566806815085.png)


使用分而治之可以合并所有建筑物！

时间复杂度为：$nlog(n)$

**思路二**：二分法

时间复杂度：$n^2log(n)$

**思路三**：堆(参考提交代码中）

大家有不清楚的地方， 欢迎留言~

## 代码：

思路一：分而治之

```python
class Solution:
    def getSkyline(self, buildings):
        if not buildings: return []
        if len(buildings) == 1:
            return [[buildings[0][0], buildings[0][2]], [buildings[0][1], 0]]
        mid = len(buildings) // 2
        left = self.getSkyline(buildings[:mid])
        right = self.getSkyline(buildings[mid:])
        return self.merge(left, right)

    # 两个合并
    def merge(self, left, right):
        # 记录目前左右建筑物的高度
        lheight = rheight = 0
        # 位置
        l = r = 0
        # 输出结果
        res = []
        while l < len(left) and r < len(right):
            if left[l][0] < right[r][0]:
                # current point
                cp = [left[l][0], max(left[l][1], rheight)]
                lheight = left[l][1]
                l += 1
            elif left[l][0] > right[r][0]:
                cp = [right[r][0], max(right[r][1], lheight)]
                rheight = right[r][1]
                r += 1
            # 相等情况
            else:
                cp = [left[l][0], max(left[l][1], right[r][1])]
                lheight = left[l][1]
                rheight = right[r][1]
                l += 1
                r += 1
            # 和前面高度比较，不一样才加入
            if len(res) == 0 or res[-1][1] != cp[1]:
                res.append(cp)
        # 剩余部分添加进去
        res.extend(left[l:] or right[r:])
        return res
```

思路二：二分法

```python
class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        import bisect
        res = [[0, 0]]
        # 记录 [left, height], [right, height]
        loc = []
        for l, r, h in buildings:
            # 为了排序让 left那边靠前, 所以让高度取负
            loc.append([l, -h])
            loc.append([r, h])
        loc.sort()
        heap = [0]

        for x, h in loc:
            if h < 0:
                bisect.insort(heap, h)
            else:
                heap.remove(-h)
            cur = -heap[0]
            if res[-1][1] != cur:
                res.append([x, cur])

        return res[1:]
```

思路三：堆

```python
class Solution:
    def getSkyline(self, buildings):
        import heapq
        events = sorted([(L, -H, R) for L, R, H in buildings] + list({(R, 0, 0) for _, R, _ in buildings } ))
        res = [[0, 0]]
        heap = [[0, float("inf")]]
        for x, H, R in events:
            while x >= heap[0][1]:
                heapq.heappop(heap)
            if H:
                heapq.heappush(heap, [H, R])
            if res[-1][1] != -heap[0][0]:
                res.append([x, -heap[0][0]])
        return res[1:]
```
[^1]: https://www.***.org/the-skyline-problem-using-divide-and-conquer-algorithm/
