
## 基本思路
所谓的同构就是同位置的字母可以形成一一对应关系， 没有一对多也没有多对一， 
一多的对应关系检查可以通过字典进行记录， 即相同的 key 必须有相同的 value
多对一的关系检查可以通过 set(), 将已经被对应的元素放入 set() 以验证已经被对应的元素不可再次被对应



```
class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) != len(t):
            return False
        d = {}           # key 为 s 的字符， value 为相同索引位置的 t 的字符
        usedChar = set() # 用来记录已经被映射的元素， 可以由此判断要映射 (s -> t) 的元素是否已经被之前其他元素映射
        for a, b in zip(s, t):
            if a not in d:
                if b not in usedChar:
                    usedChar.add(b) # 记录映射关系
                    d[a] = b        # 记录被映射过的元素
                else:               # 出现了多对一的情况
                    return False
            else:
                if d[a] != b:       # 出现一多对多的情况
                    return False
        return True
```
