### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def hasGroupsSizeX(self, deck):
        """
        :type deck: List[int]
        :rtype: bool
        """
        def find(a,b):
            #寻找最大公因子
            while b!=0:
                a,b=b,a%b
            return a

        if len(deck)==1:
            return False
        hashmap={}
        for i in deck:
            hashmap[i]=hashmap.get(i,0)+1
        l=[value for value in hashmap.values()]
        for i in range(1,len(l)):
            l[i]=find(l[i],l[i-1])
        return l[-1]>=2
```