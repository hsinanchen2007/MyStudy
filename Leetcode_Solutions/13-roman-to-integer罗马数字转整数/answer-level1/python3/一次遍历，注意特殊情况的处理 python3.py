# 题解
借助哈希表保存所有的罗马字符，包括'I':1, 'IV':4, 'V':5, 'IX':9, 'X':10, 'XL':40, 'L':50, 'XC':90, 'C':100, 'CD':400, 'D':500, 'CM':900, 'M':1000。


## 一次遍历

 1. 初始化词典$Roman2Num=\{'I':1, 'IV':4, 'V':5, 'IX':9, 'X':10, 'XL':40, 'L':50, 'XC':90, 'C':100, 'CD':400, 'D':500, 'CM':900, 'M':1000\}$。初始化$res=0$。$n$为字符串长度。开始索引$i=0$
 2. 循环条件$i<n$：
 	+ 若$i==n-1$，表示已经判断到最后一位，不存在'IV':4等两个字符的情况。此时：$i+=1$，$res+Roman2Num[s[i]]$
 	+ 否则：
 		+ 需要先判断当前字符和下一字符是否构成特殊的表示方式，即$s[i,i+1]$是否在$Roman2Num$中。若在：$i+=2$,$res+=Roman2Num[s[i,i+1]]$
 		+ 否则，表示单个字符即可， $i+=1$，$res+Roman2Num[s[i]]$
 
 3. 返回$res$

	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
### 复杂度分析
 - 时间复杂度：$O(n)$
 - 空间复杂度：$O(1)$

### Python
```python
class Solution:
    def romanToInt(self, s: str) -> int:
        Roman2Num={'I':1, 'IV':4, 'V':5, 'IX':9, 'X':10, 'XL':40, 'L':50, 'XC':90, 'C':100, 'CD':400, 'D':500, 'CM':900, 'M':1000}
        n=len(s)
        i=0
        res=0
        while(i<n):
            if(i==n-1):
                res+= Roman2Num[s[i]]
                i+=1
            else:
                if(s[i:i+2] in Roman2Num):
                    res+=Roman2Num[s[i:i+2]]
                    i+=2
                else:
                    res+= Roman2Num[s[i]]
                    i+=1
        return res
```
