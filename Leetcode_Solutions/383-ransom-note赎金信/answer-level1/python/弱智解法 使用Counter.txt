### 解题思路
提交完了才发现有大神用Counter 之后做减法, 有剩余就是Flase.
其实做题就是练手. 
思路加注释了


### 代码

```python3
from collections import Counter
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        rc = Counter(ransomNote)
        mc = Counter(magazine)
        flag = True   #Flase的情况都直接返回,只有循环完还是True才返回True                        
        for r in rc.keys(): 
            if r not in mc.keys():
                return not flag #循环ransomNote里的字符 如果不在magazine 直接返回False
            else:
                if rc.get(r) > mc.get(r): 
                    #如果在magazine里 就比较字符的个数, 如果ransomNote的多直接返回Flase
                    return not flag
                else:
                    flag = True
        return flag
                
```