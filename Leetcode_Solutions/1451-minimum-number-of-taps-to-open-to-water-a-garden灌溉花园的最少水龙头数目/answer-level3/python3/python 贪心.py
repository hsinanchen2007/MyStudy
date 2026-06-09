这题目 18 年初实习面试的时候被问过。线段覆盖问题。**贪心算法**。面试的时候我想的使用递归方法，这次写的是迭代。

思路是：
先把每个水龙头的范围转化成区间，弄成一个区间数组。
比如 示例 1

![1685_example_1.png](https://pic.leetcode-cn.com/a5b098cf611e6951a134a4221e192325da468b908cabb123b3d42d765e5c698a-1685_example_1.png)

转换成：

[[0, 3], [0, 5], [1, 3], [2, 4]]

这里做了两个优化：
1. 长度为零的就忽略了
2. 超出 0 到 n 范围的就截止到 [0, n] 区间内

然后我们可以在按照区间的左端点排序。（上面的数组已经是这个顺序了）

其实另外还有一个优化：如果一个区间被另一个区间完全覆盖了，那这个区间也是无效的，应该删掉，例如 [1, 3] 完全落在 [0, 3] 内。

结果这里就只剩下 [0, 5] 了：
[[0, 5]]

所以这个例子不好，可以看下示例 3

n = 7, ranges = [1,2,1,0,2,1,0,1]

经过上述操作后剩下的区间其实也只有刚好三个了：
[(0, 3), (2, 6), (6, 7)]
所以干脆去掉

之后的做法是：

如果这个区间数量是 0 或者第一个区间不能覆盖 0，直接返回 -1
然后就开始贪心：
1. 第一个区间必选，ans 变量计已选的区间数
2. 判断是否可以覆盖，如果可以，返回 ans
3. 从下一个区间开始，所有可以选择的区间（如果这个区间的左端点小于等于上一个选中区间的右端点，就可以选）中找一个右端点最大的，选择，如果没有可选的，返回 -1

这个代码写的不够精炼

```python
class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        # ranges 转化为区间
        seg = []
        for i in range(n+1):
            if ranges[i] > 0:
                seg.append((max(0, i - ranges[i]), min(n, i + ranges[i])))
        # 去掉被其他区间覆盖的区间
        s2 = {}
        for s in seg:
            if s[0] not in s2:
                s2[s[0]] = []
            s2[s[0]].append(s)
        seg = []
        for k in s2:
            t = s2[k][0]
            for xx in s2[k]:
                if xx[1] > t[1]:
                    t = xx
            seg.append(t)
        s2 = {}
        for s in seg:
            if s[1] not in s2:
                s2[s[1]] = []
            s2[s[1]].append(s)
        seg = []
        for k in s2:
            t = s2[k][0]
            for xx in s2[k]:
                if xx[0] < t[0]:
                    t = xx
            seg.append(t)
            
            
        seg.sort(key=lambda x: x[0]) # 按区间左端点排序
 
        
        if not seg or seg[0][0] != 0: # 区间数量是 0 或者第一个区间不能覆盖 0，直接返回 -1
            return -1
        
        i = 0
        ans = 1
        while seg[i][1] != n:
            nx = i
            j = 1 + i
            while j < len(seg) and seg[j][0] <= seg[i][1]:
                if seg[nx][1] < seg[j][1]:
                    nx = j
                j += 1
            if nx == i:
                return -1
            ans += 1
            i = nx
        return ans
```

欢迎访问我的博客 [https://codeplot.top/](https://codeplot.top/)

我的博客的[刷题分类](https://codeplot.top/categories/%E5%88%B7%E9%A2%98/)