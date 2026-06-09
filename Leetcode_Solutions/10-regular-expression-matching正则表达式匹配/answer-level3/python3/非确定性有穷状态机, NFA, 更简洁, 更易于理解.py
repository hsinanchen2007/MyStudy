```
# -*- coding: utf-8 -*-

# Author: Cynthia

"""
    方法3, 非确定性有穷状态机, NFA
    a*b*c*拼个$方便到达终节点, a*b*c*$节点数是去掉*之后的字符数量+1
    数据结构:
    self.n, 节点个数, 0表示首节点, n-1为终节点
    self.e, 边, (这题其实用不到):
        {
            0: {1: ['a', 'b']},
            2: {2: ['c']}
        }
    self.m, 动作, 格式:
        {
            0: {'a': [2, 3]},
            1: {'c': [1, 2]}
        }
"""
from collections import defaultdict


class Graph:
    def __init__(self, p):
        # a*b*c*->a*b*c*$
        self.p = p+'$'

        self.n = 0

        self.m = {}

        self.createNFA()

    def createNFA(self):
        # 计算总节点数
        self.n = 1+len(self.p.replace("*", ""))
        # 初始化动作
        for v in range(self.n):
            self.m[v] = defaultdict(list)
        # 初始状态位于首节点, i用作p索引, v为NFA当前节点
        p, i, v = self.p, 0, 0
        while p[i:]:

            # 处理x*的情况
            if p[i+1:] and p[i+1] == '*':
                # v通过p[i]可以到达v+1, v+1可以通过p[i]自循环
                self.m[v][p[i]].append(v+1)
                self.m[v+1][p[i]].append(v+1)
                i2, v2 = i, v
                # x*y*z, 则存在v直接通过y到达v+2的边, 直接通过z到v+3
                while p[i2+1:] and p[i2+1] == '*' and p[i2+2:]:
                    self.m[v][p[i2+2]].append(v2+2)
                    i2, v2 = i2+2, v2+1
                i, v = i+2, v+1
            # 处理非x*的情况
            else:
                self.m[v][p[i]].append(v+1)
                i, v = i+1, v+1

    def DFS(self, s):
        # aaa$, a*b*c*$, 加$是为了构造唯一终节点
        s = s+'$'

        def rf(s, v):
            # s遍历完了, 看到终节点了吗
            if not s: return v == self.n-1

            # s没遍历完, 看当前节点通过s[0]能到的下一个节点是什么, 去深度遍历
            # 有一条路能走到头, 就直接返回True, 不再继续执行
            for c in self.m[v][s[0]]+self.m[v]['.']:
                if rf(s[1:], c):
                    return True
            # 如果没有一条路能走到头(包括不存在动作s[0]的情况)
            return False

        return rf(s, 0)


class Solution:

    def isMatch(self, s: str, p: str) -> bool:
        g = Graph(p)
        return g.DFS(s)


s = Solution()
print(s.isMatch("aaa", "a*b*c*"))

```
