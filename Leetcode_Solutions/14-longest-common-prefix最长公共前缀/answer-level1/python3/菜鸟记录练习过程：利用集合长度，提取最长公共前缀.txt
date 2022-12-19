1、空列表、空字符串直接返回“”
2、计算strs非空字段的最小长度
3、从左到右依次取出strs每个元素的第i位，直至minset长度不为一，返回拼接的字符串result
```
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:     
        if not strs:
            return ""
        for s in strs:
            if len(s) == 0:
                return ""
            else:
                min_ele = min(len(i) for i in strs)
                result = ""
                for i in range(0, min_ele):
                    minset = set()
                    for s in strs:
                        minset.add(s[i])
                    if len(minset) == 1:
                        result = result + strs[0][i]
                    else:
                        break
                return result
```
![最长公共前缀.png](https://pic.leetcode-cn.com/6b40a48594ebdde758c292ba3ee137835ee1593378ef871213cce3bb4fa452ed-%E6%9C%80%E9%95%BF%E5%85%AC%E5%85%B1%E5%89%8D%E7%BC%80.png)
