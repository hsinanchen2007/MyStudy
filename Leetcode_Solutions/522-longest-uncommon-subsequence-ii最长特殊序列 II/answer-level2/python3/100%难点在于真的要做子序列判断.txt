![image.png](https://pic.leetcode-cn.com/c5cd4a78e6bec8aaed8852b4380f8c4e14ec46f3d266125fc693246b43209308-image.png)

先按长度降序排词，然后字典化，从前往后遍历找数量唯一的词，然后再从看是否是比自己长的词的子序列，如果确定不是其他词的子序列就输出，反之继续

```
class Solution:
    def findLUSlength(self, strs: List[str]) -> int:
        strs.sort(key=lambda x:-len(x))
        d=collections.defaultdict(int)
        for i in strs:
            d[i]+=1
        
        def f(a,b):
            k=0
            for c in a:
                j=b.find(c,k)
                if j==-1:
                    return False
                k=j+1
            return True
        
        for i in d:
            if d[i]==1:
                flag=True       
                for j in d:
                    if j==i:        #碰到自己时不能直接break，因为同长度的可能还有其他词
                        continue
                    elif f(i,j):        #判断子序列
                        flag=False
                        break
                    elif len(j)>len(i):     #长度小于自己时就跳出循环
                        break
                if flag:        #如果在比自己长的词里面，没有找到子序列，那就输出自己的长度
                    return len(i)
                
        return -1
```
