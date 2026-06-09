### 解题思路
用等差数列求和来做
结果list中每个元素都是一个等差数列，每个等差数列之和都是target，公差为1，这样只需要遍历项数n，求出每个长度为n的等差数列的首项就可以得这个等差数列

### 代码

```python3
class Solution:
    def first(self,target,n): # 求等差数列首项
        return (target/n)-(n-1)/2

    def AP(self,fir,n): # 等差数列 an=a1+(n-1)*d
        return int(fir+(n-1))

    def findContinuousSequence(self, target: int) -> List[List[int]]:
        re=[]
        element=[]
        if target<=2:
            return re
        else:
            for n in range(2,target):
                f=self.first(target,n)
                if (f>0)&(f%1==0):
                    element=[self.AP(f,x+1)for x in range(n)]
                    re.append(element)
        l=len(re)
        result=[[] for j in range(l)]
        for x in range(l):
            result[x]=re[l-x-1]
        return result


```