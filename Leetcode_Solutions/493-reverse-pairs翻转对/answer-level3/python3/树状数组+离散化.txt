这题和求逆序数很像，自然而然就想到了线段树。但是线段树一直 TLE，我测试了没过的几组，都会超过 1000ms。。。

所以是 LC 的数据在卡线段树的常数，换成树状数组直接过了。

```python
class Solution:
    def __init__(self):
        self.bit = []
        self.n = 0
        
    def query(self, i: int):
        s = 0    
        while i > 0:
            s += self.bit[i]
            i -= i & -i
        return s    
    
    def update(self, i: int, x: int = 1):
        while i <= self.n:
            self.bit[i] += x 
            i += i & -i
    
    def reversePairs(self, nums: List[int]) -> int:
        # 先离散化
        x = list(set(nums))
        nn, ind = sorted(list(set(x + list(map(lambda a: 2 * a, x))))), 1
        disc = {}
        for n in nn:
            disc[n] = ind
            ind += 1
        self.n, self.bit = ind, [0 for _ in range(ind + 5)]
        ret = 0
        for n in nums:
            if ind >= disc[n * 2]:
                ret += self.query(i=ind) - self.query(i=disc[n * 2])
            self.update(disc[n])
        return ret    
```


也附上被卡的线段树代码：

```python
#
# @lc app=leetcode.cn id=493 lang=python3
#
# [493] 翻转对
#
class Solution:
    
    def __init__(self):
        self.tree = []

    def push_up(self, rt: int):
        self.tree[rt] = self.tree[rt << 1] + self.tree[rt << 1 | 1]
        
    def update(self, i: int, l: int, r: int, rt: int):    
        if l == r:
            self.tree[rt] += 1
            return
        m = (l + r) >> 1
        if i <= m:
            self.update(i, l, m, rt << 1)
        else:
            self.update(i, m + 1, r, rt << 1 | 1)
            
        self.push_up(rt)

    def query(self, L: int, R: int, l: int, r: int, rt: int):
        if L <= l and r <= R:
            return self.tree[rt]
        m, ret = (l + r) >> 1, 0
        if L <= m:
            ret += self.query(L, R, l, m, rt << 1)
        if R > m:
            ret += self.query(L, R, m + 1, r, rt << 1 | 1)
        return ret

    def reversePairs(self, nums: List[int]) -> int:
        import copy
        # 先离散化
        x = list(set(nums))
        nn, ind = sorted(list(set(x + list(map(lambda a: 2 * a, x))))), 1
        disc = {}
        for n in nn:
            if n not in disc:
                disc[n] = ind
                ind += 1
        
        #print(disc)
        # 初始化线段树
        self.tree, ret = [0 for _ in range(ind * 4 + 5)], 0
        
        for n in nums:
            if disc[n * 2] + 1 < ind:
                ret += self.query(disc[n * 2] + 1, ind, 1, ind, 1)
            self.update(disc[n], 1, ind, 1)    
        return ret    


```