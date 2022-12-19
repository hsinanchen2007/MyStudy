先假设有以下几种情况：
（1）x==1 and y==1:   如果bound小于2返回空，否则返回2
（2）x==1 or y==1:   从较大的数逐渐增加幂次直到bound，返回遍历的结果
（3）x和y都不为1时：  从x的零次幂开始，y的幂次逐渐增加直到x+y>=bound
                    从x的一次幂开始，y的幂次逐渐增加直到x+y>=bound。。。。
                    直到x的幂次加上y的幂次大于等于bound，结束遍历

代码如下：
```
class Solution:
    def powerfulIntegers(self, x: int, y: int, bound: int) -> List[int]:
        if x==1 and y==1 and bound>=2:
            return [2]
        if x==1 and y==1 and bound<2:
            return None
        res=[]
        if x==1 or y==1:
            c=max(x,y)
            m=0
            while c**m+1<=bound:
                res.append(c**m+1)
                m+=1
            return res
        
        a=0
        b=0
        while x**a+y**b<=bound:
            while x**a+y**b<=bound:
                if x**a+y**b not in res:
                    res.append(x**a+y**b)
                b+=1
            a+=1
            b=0
        return res
            
```

