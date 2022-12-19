```
# -*- coding: utf-8 -*-

# Author: Cynthia

"""
    题目分析: 给定n对括号, 生成所有符合条件的字符串, 比如2对:
    ["(())", "()()"]
"""
from typing import List


class Solution:

    def generateParenthesis(self, n: int) -> List[str]:
        ans = []

        # s用于传递拼接的字符, p用于标明处理到第几个左括号, count表示已经拼接了几个右括号
        def rf(s, p, count, n):

            if p == n:
                ans.append(s+"("+")"*(n-count))
                return

            # 第p个左括号右边可拼接的最多右括号取以下三个最小值:
            # p: p个左最多p个右; n-count: 就剩这么多了; n-count-(n-p), 还得给剩下的留点
            # 算出来直接取p-count就行, 不过直接想肯定想不出来的.
            for i in range(p-count+1):

                rf(s+"("+")"*i, p+1, count+i, n)

        rf("", 1, 0, n)
        return ans


s = Solution()
print(s.generateParenthesis(3))

```
