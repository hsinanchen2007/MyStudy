# 题解
## 标志转向

 1. 特判，若行数$numRows<2$，返回$s$
 2. 初试化$res=["",\cdots,""]$，长度为$numRows$，$res[i]$表示第$i$行存放的字符。
 3. 初始化标志$flag=-1$，初试行$i=0$
 4. 遍历字符串中每一个字符$c$：
 	+ 若$i==0\ or\ i==numRows-1$，说明应该更换方向，向下为$1$，向上为$-1$，因此$flag=-flag$
 	+ 将当前字符$c$填入对应行$i$。
 	+ 更新行$i=i+flag$
 
 5. 将$res$中各行连接起来并返回。

                                                                                                                                                      
### 复杂度分析
 - 时间复杂度：$O(n)$
 - 空间复杂度：$O(n)$

### Python
```python
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if(numRows<2):
            return s
        res=[""]*numRows
        n=len(s)
        flag=-1
        i=0
        for c in s:
            res[i]+=c
            if(i==0 or i==numRows-1):flag=-flag
            i+=flag
        return "".join(res)
```