求这些建筑物的所构成的轮廓线，可以理解为要返回轮廓线上每条水平线左边的坐标集合；

#### 思路：

- 离散化 + 带懒惰标记的线段树（对区间进行更新）
- 先对建筑物的横坐标做离散化处理，将矩形两个 x 坐标全部放在一起进行排序，并保留坐标和下标之间的对应关系；
- 再将建筑物一个一个插入树中，因为不要房子右边的点，而且有的房子右边的点可能和其他更低的房子相交，所以右边坐标下标 $-1$ 再插入（更新），更新区间高度为最大值；
- 高度h作为懒惰标记，当访问到h>0的节点并且要继续向下访问时需要向子树更新；
- 最后这个节点查询高度。

线段树更新过程如下：

![天际线问题.jpg](https://pic.leetcode-cn.com/0fd8ac96b5460d888c20415727c234afa8ca05e6d4265978509ebb55acb58407-%E5%A4%A9%E9%99%85%E7%BA%BF%E9%97%AE%E9%A2%98.jpg){:width=500}
{:align=center}

#### 代码：
```Python []
class Node:
    def __init__(self):
        self.l = 0
        self.r = 0
        self.h = 0
class Solution(object):
    def getSkyline(self, buildings):
        """
        :type buildings: List[List[int]]
        :rtype: List[List[int]]
        """
        global mp, mp2, index, Tree
        mp = {}
        mp2 = {}
        index = []
        
        if len(buildings) == 0:
            return []
        
        for i in range(len(buildings)):
            for j in range(2):
                if buildings[i][j] not in mp:
                    mp[buildings[i][j]] = 1
                    index.append(buildings[i][j])
        index.sort()
        for i in range(len(index)):
            mp[index[i]] = i
            mp2[i] = index[i]
        print index
        print mp
        print mp2
        maxn = len(index)
        Tree = [Node() for i in range(maxn << 2)]
        self.build(0, maxn, 0)
        res = []
        for i in range(len(buildings)):
            self.update(mp[buildings[i][0]], mp[buildings[i][1]]-1, buildings[i][2], 0)
        self.query(res, 0)
        return res
    def build(self, l, r, rt):
        Tree[rt].l = l
        Tree[rt].r = r
        if l == r:
            return
        m = (l+r) / 2
        self.build(l, m, 2*rt+1)
        self.build(m+1, r, 2*rt+2)

    def update(self, l, r, h, rt):
        if Tree[rt].h >= h:
            return
        if Tree[rt].l == l and Tree[rt].r == r:
            Tree[rt].h = h
            return
        if Tree[rt].h > 0:
            Tree[rt*2+1].h = max(Tree[rt].h, Tree[rt*2+1].h)
            Tree[rt*2+2].h = max(Tree[rt].h, Tree[rt*2+2].h)
            Tree[rt].h = 0
        mid = (Tree[rt].l + Tree[rt].r) / 2
        if r <= mid:
            self.update(l, r, h, rt*2+1)
        elif l > mid:
            self.update(l, r, h, rt*2+2)
        else:
            self.update(l, mid, h, rt*2+1)
            self.update(mid+1, r, h, rt*2+2)

    def query(self, res, rt):
        if Tree[rt].l == Tree[rt].r:
            if res and Tree[rt].h == res[-1][1]:
                return
            tmp = [mp2[Tree[rt].l], Tree[rt].h]
            res.append(tmp)
            return
        if Tree[rt].h > 0:
            Tree[rt * 2 + 1].h = max(Tree[rt].h, Tree[rt * 2 + 1].h)
            Tree[rt * 2 + 2].h = max(Tree[rt].h, Tree[rt * 2 + 2].h)
            Tree[rt].h = 0
        self.query(res, rt*2+1)
        self.query(res, rt*2+2)
```