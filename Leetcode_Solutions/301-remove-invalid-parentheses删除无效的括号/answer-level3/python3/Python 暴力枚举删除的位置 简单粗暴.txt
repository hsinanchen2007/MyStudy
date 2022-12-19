![image.png](https://pic.leetcode-cn.com/3d4aa63dfa2b59957690e614432b792ef47be3818feb84ff4afd67224774fdd9-image.png)


```
'''
先计算需要删除的左括号和右括号数量
然后用组合方式枚举所有可能的删除位置, 判断剩下的字符串是否合法
'''

from typing import List
from itertools import combinations
from functools import lru_cache
class Solution:

    # 返回不匹配的左括号和右括号数量，没有左括号和其配对的右括号是多余的，配对完成后剩下的左括号也是多余的
    @lru_cache(typed=False)
    def getUnpairCnt(self, s: str):
        l_cnt, r_cnt = 0, 0
        for ch in s:
            if ch == '(':
                l_cnt += 1
            elif ch == ')':
                if l_cnt == 0:
                    r_cnt += 1
                else:
                    l_cnt -= 1
        return [l_cnt, r_cnt]

    def removeInvalidParentheses(self, s: str) -> List[str]:
        l_pos = [pos for pos in range(len(s)) if s[pos] == '(']
        r_pos = [pos for pos in range(len(s)) if s[pos] == ')']
        l_cnt, r_cnt = self.getUnpairCnt(s)

        ans = set()
        for l_del in combinations(l_pos, l_cnt):
            for r_del in combinations(r_pos, r_cnt):
                del_set = set(list(l_del) + list(r_del))
                new_str = ''.join([s[i] for i in range(len(s)) if i not in del_set])
                #print(new_str)
                ret = self.getUnpairCnt(new_str)
                if ret == [0, 0]:
                    ans.add(new_str)
        return list(ans)
```
