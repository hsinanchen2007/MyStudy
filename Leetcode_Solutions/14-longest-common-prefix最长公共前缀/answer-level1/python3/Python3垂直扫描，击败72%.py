# 逐个对比
```
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if strs == []: return ""

        res = ""
        
        for l in range(len(strs[0])):
            flag = 0
            for n in range(1,len(strs)):
                try:
                    flag = flag + 1 if strs[0][l] == strs[n][l] else flag
                except:
                    return res
            if flag == len(strs)-1:
                res += strs[0][l]
            else:
                return res

        return res
```
1. 时间复杂度Os,s为字符串总长度，空间复杂度O1
2. 其实可以选出最短字符串Smin,减去try-except代码
3. 通过垂直扫描、逐个对比，遇到短字符末尾返回，遇到不匹配返回
