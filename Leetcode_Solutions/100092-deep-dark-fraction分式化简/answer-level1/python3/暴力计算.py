字符串反转，然后依次计算
```
class Solution(object):
    def fraction(self, cont):
        """
        :type cont: List[int]
        :rtype: List[int]
        """
        cont.reverse()
        res = [cont[0],1]
        for i in range(0,len(cont)-1):
            temp=res[1]
            res[1]=res[0]
            res[0]=cont[i+1]*res[1]+temp
        return res
```
