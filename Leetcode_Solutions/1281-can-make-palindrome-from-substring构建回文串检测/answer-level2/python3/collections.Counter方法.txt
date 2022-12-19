回文串那里的规律是在剔除成对出现的字符之后,剩下的单字符组成的字符串计数.

在计数之后直接计算k是否达到了剩余字符串长度的一半,达到一半就返回True.

```import collections

class Solution:
    def canMakePaliQueries(self, s: str, queries: List[List[int]]) -> List[bool]:
        res = list()
        for query in queries:
            if query[2] >= 13:
                res.append(True)
                continue
            tmp = s[query[0]:query[1] + 1]
            size = query[1] - query[0] + 1
            dic = collections.Counter(tmp)
            
            alph = 0
            for key in dic.keys():
                if dic[key] % 2 == 1:
                    alph += 1

            if query[2] >= (alph // 2):
                res.append(True)
            else:
                res.append(False)
        
        return res```