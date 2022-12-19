一 算法设计
1 逐列水平扫描
时间复杂度O(S),其中S为列表中所有字符串的总字符个数；空间复杂度O(1)
2 利用python3中zip(*)
二 python3实现
```
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        #if len(strs) == 0:
        #    return ""
        
        #res = ""
        #n = len(strs)
        #s0 = strs[0]
        #m = len(s0)
        #for i in range(m):
        #    ch = s0[i]
        #    for j in range(1, n):
        #        try:
        #            if strs[j][i] != ch:
        #                return res
        #        except:
        #            return res
        #    res += ch
        #return res
        
        
        # method2
        res = ""
        for i in zip(*strs):
            if len(set(i)) == 1:
                res += i[0]
            else:
                break
        return res
```
