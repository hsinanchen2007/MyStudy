```
class Solution(object):
    def circularPermutation(self, n, start):
        """
        :type n: int
        :type start: int
        :rtype: List[int]
        """
        
        # 格雷码，生成规则如下：
        # 从1开始
        # 0 1
        # 添加0变成 00 01
        # 添加1反向 11 19
        # 按照这个思路做
        if n <= 0:
            return []
        if start >= 2**n:
            return []
        
        res = ['0', '1']
        self.walk(n, res, 1)
        res = list(map(lambda a: int(a, 2), res))
        idx = res.index(start)
        return res[idx:]+res[:idx]
        
    def walk(self, n, res, start):
        
        if start == n:
            return
        
        temp = []
        while res:
            temp.append(res.pop(0))
            
        for i in temp:
            res.append('0'+i)
            
        for i in temp[::-1]:
            res.append('1'+i)
        
        start+=1
        
        
        self.walk(n, res, start)
        return
```
