### 解题思路
此处撰写解题思路
排序解决问题，这里的排序是参考题解里面的一位[道友](https://leetcode-cn.com/problems/permutation-ii-lcci/solution/python-li-yong-pai-xu-qu-zhong-de-hui-su-fa-ji-bai/)的
，可以去看一看，思路很好。

一道很好的回溯的练习题目

### 代码

```python3
from itertools import permutations
class Solution:
    def permutation(self, S: str) -> List[str]:
        # 1064ms
        # ans = set()
        # n = len(S)
        # def helper(s,t):
        #     r = "".join(t) if t else ''
        #     if len(t)==n and r not in ans:
        #         ans.add(r)

        #     for i in range(len(s)):
        #         t.append(s[i])
        #         helper(s[:i]+s[i+1:],t)
        #         t.pop()
        # t = []
        # helper(S,t)
        # return list(ans)

        # 72ms 
        # res = []    # 定义全局变量保存最终结果
        # state = ""  # 定义状态变量保存当前状态
        # s = set()   # 定义条件变量
        # def back(state, S):
        #     if state in s:
        #         return
        #     s.add(state)
        #     if len(S)==0: # 状态满足最终要求
        #         res.append(state)   # 加入结果
        #         return 
        #     for i in range(len(S)):
        #         back(state+S[i],S[:i]+S[i+1:])
        # back(state,S)
        # return res

        # 44ms 排序之后的这个不得不承认快很多。
        # https://leetcode-cn.com/problems/permutation-ii-lcci/solution/python-li-yong-pai-xu-qu-zhong-de-hui-su-fa-ji-bai/
        ans = []
        S = sorted(S)

        def backtrack(r, s):
            if not len(s):
                ans.append(r)
            else:
                pre = ''
                for i in range(len(s)):
                    if s[i] != pre:
                        backtrack(r + s[i], s[:i] + s[i + 1:])
                    pre = s[i]

        backtrack('', S)
        return ans

        # 76ms 偷懒做法
        # ans = []
        # for i in set(permutations(S)):
        #     ans.append(''.join(i))
        # return ans

```