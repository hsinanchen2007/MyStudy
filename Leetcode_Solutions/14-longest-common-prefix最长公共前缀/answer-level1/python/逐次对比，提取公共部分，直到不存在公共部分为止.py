### 解题思路
此处撰写解题思路:
逐次对比，提取公共部分，直到不存在公共部分为止

### 代码

```python
class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not strs:
            return ""
        else:
            iflag = 0
            gstr = ''
            nstr = strs[0]
            for sstr in strs:
                nlen = len(nstr)
                slen = len(sstr)
                glen = min(nlen,slen)
                for i in range(0,glen):
                    if sstr[i] == nstr[i]:
                        gstr = gstr + sstr[i]
                        iflag = 1
                    else:
                        break
                if iflag == 0:
                    return ""
                nstr = gstr
                gstr =''
            return nstr

        
```