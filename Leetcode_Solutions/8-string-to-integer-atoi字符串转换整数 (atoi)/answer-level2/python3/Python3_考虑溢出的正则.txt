## 两个要点  
1. **如何利用正则表达式正确提取出有效数字?**
   > 答: 利用正则匹配的**分组**,提取出**符号字符串`signTxt`+ 前导符0字符串`zeroTxt` + 有效数字字符串`numTxt`**,其中`zeroTxt`是不需要的  
所以实际有效数字的组合就是 **`signTxt` + `numTxt`**
2. **对于有效数字如何处理溢出?**
   > 答: **比较字符串长度和字符串大小**,`INT_MIN`和`INT_MAX`不考虑符号的情况下,长度均为10,且均可转为数字字符串  
用来和`numTxt`比较字符串长度和大小情况,以此确定是否溢出  

具体请看代码
```
import re
class Solution:
    def myAtoi(self, str: str) -> int:
        minTxt, maxTxt = '2147483648', '2147483647'
        ## 分成三组, \1:符号, \2:前导符0, \3:有效数字
        r = re.match(r'^\s*([+-]?)(0*)([0-9]+)', str) 
        if not r: # 不匹配
            return 0
        signTxt = r.group(1) # 符号
        numTxt = r.group(3) # 有效数字, 默认不溢出
        if signTxt == '-':
            if len(numTxt) > 10:
                numTxt = minTxt
            elif len(numTxt) == 10 and numTxt > minTxt:
                numTxt = minTxt
        else:
            if len(numTxt) > 10:
                numTxt = maxTxt
            elif len(numTxt) == 10 and numTxt > maxTxt:
                numTxt = maxTxt
                
        return int(signTxt + numTxt)
        
```