思路借鉴了George大佬的
```
class Solution(object):
    def fraction(self, cont):
        """
        :type cont: List[int]
        :rtype: List[int]
        """
        #设a分子b分母
        #c+a/b=(bc+1)/b
        #c2+b/(bc+a)=>b=bc+a,a=b
        #遍历
        a=1
        b=cont[-1]
        #从倒数第二个开始取c
        for c in cont[:-1][::-1]:
            a,b=b,(c*b+a)
        return [b,a]
```
