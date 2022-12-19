开始做成了成段增减。。做完返现原来题目里的正方形是不能打散的。

所以改成了成段替换。思路大概是：

1. 先取出填放位置的高度 `current_height`;
2. 增加当前方块的高度 `hope_height = current_height + height`
3. 成段更新 `update(l, r, hope_height, 1, N, 1)`;
4. 全量查询最大值 `query(1, N, 1, N, 1)`;

```python
#
# @lc app=leetcode.cn id=699 lang=python3
#
# [699] 掉落的方块
#
class Solution:
    def __init__(self):
        self.add = []
        self.mmm = []
        self.res = []
        
    def push_up(self, rt: int):
        self.mmm[rt] = max(self.mmm[rt << 1], self.mmm[rt << 1 | 1])
        
    def push_down(self, rt: int):
        if (self.add[rt] > 0):
            self.add[rt << 1] = self.add[rt]
            self.add[rt << 1 | 1] = self.add[rt]
            self.mmm[rt << 1] = self.add[rt]
            self.mmm[rt << 1 | 1] = self.add[rt]
            self.add[rt] = 0
            
    def update(self, L: int, R: int, c: int, l: int, r: int, rt: int):
        if L <= l and r <= R:
            self.add[rt] = c        
            self.mmm[rt] = c
            return
        self.push_down(rt)
        m = (l + r) >> 1
        if L <= m:
            self.update(L, R, c, l, m, rt << 1)
        if m < R:
            self.update(L, R, c, m + 1, r, rt << 1 | 1)    
        self.push_up(rt)    
        
    
    def query(self, L: int, R: int, l: int, r: int, rt: int):
        if L <= l and r <= R:
            return self.mmm[rt]
        self.push_down(rt)
        m, ret = (l + r) >> 1, 0
        if L <= m:
            ret = max(ret, self.query(L, R, l, m, rt << 1))
        if m < R:
            ret = max(ret, self.query(L, R, m + 1, r, rt << 1 | 1))
        return ret    

    def fallingSquares(self, positions: List[List[int]]) -> List[int]:
        xx = []
        for p in positions:
            xx.append(p[0])
            xx.append(p[0] + p[1] - 1)
        poses, ind = sorted(list(set(xx))), 1
        desc = {}
        for p in poses:
            if p not in desc:
                desc[p] = ind
                ind += 1
        #print(desc)
        self.add = [0 for _ in range(ind << 2)]
        self.mmm = [0 for _ in range(ind << 2)]
        ret = []
        for ps in positions:
            l, r = desc[ps[0]], desc[ps[0] + ps[1] - 1]
            cur_height = self.query(l, r, 1, ind, 1)
            hop_height = cur_height + ps[1]
            #print(l, r)
            #print("cur", cur_height)
            #print("hop", hop_height)
            self.update(l, r, hop_height, 1, ind, 1)
            ret.append(self.query(1, ind, 1, ind, 1))
        return ret    
```