关于线段树基础知识可查看我的公众号 [线段树基础与 RMQ 问题](https://mp.weixin.qq.com/s/Wc4RCXlxe1a3RDwg_WzOyg)。
这题要注意的是，不是一颗标准的完全二叉树，所有数组空间开大一点就好了。

```python
#
# @lc app=leetcode.cn id=307 lang=python3
#
# [307] 区域和检索 - 数组可修改
#
class NumArray:

    def __init__(self, nums: List[int]):
        self.tree = [0 for _ in range(3 * len(nums) + 10)]
        self.nums = nums
        self.index = 0
        self.lens = len(nums)
        if self.lens > 0:
            self.build(1, self.lens, 1)
        
    def push_up(self, rt: int):
        self.tree[rt] = self.tree[rt << 1] + self.tree[rt << 1 | 1]

    def build(self, l: int, r: int, rt: int):
        if l == r:
            self.tree[rt] = self.nums[self.index]
            self.index += 1
            return 
        m = (l + r) // 2
        self.build(l, m, rt * 2)
        self.build(m + 1, r, rt * 2 + 1)
        self.push_up(rt)

    def _update(self, i: int, val: int, l: int, r: int, rt: int):
        if l == r:
            self.tree[rt] = val
            return
        m = (l + r) // 2
        if i <= m:
            self._update(i, val, l, m, rt * 2)
        else:
            self._update(i, val, m + 1, r, rt * 2 + 1)
        self.push_up(rt)

    def update(self, i: int, val: int) -> None:
        self._update(i + 1, val, 1, self.lens, 1)

    def _sumRange(self, L: int, R: int, l: int, r: int, rt: int) -> int:
        if L <= l and r <= R:
            return self.tree[rt]
        m, ret = (l + r) // 2, 0
        if L <= m:
            ret += self._sumRange(L, R, l, m, rt * 2)
        if R > m:
            ret += self._sumRange(L, R, m + 1, r, rt * 2 + 1)
        return ret

    def sumRange(self, i: int, j: int) -> int:
        return self._sumRange(i + 1, j + 1, 1, self.lens, 1)

# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(i,val)
# param_2 = obj.sumRange(i,j)


```