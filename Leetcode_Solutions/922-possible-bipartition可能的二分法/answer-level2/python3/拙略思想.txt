杂言：一开始总思考着把所有的元素（1->N）都涉及，然后根据dislikes数组进行排除，费时费力，后面就在思考这个主要关系应该是dislikes的关系，跟N完全无关,又开始思考建立二维数组进行回溯，太繁琐了而且个人也不是很会回溯法的编写。最后不管啥先编到无错超时后再修正。
思路：将dislikes数组进行二分编排，互不喜欢的处于对立数组中，从头开始编入两个对立数组a,b。若dislikes中存在互不关联的几个部分（既数字完全不同）则会出现分割现象，而且空列表和任意非空列表也是互不关联的，所以对dislikes进行分割，当进行到互不关联的时候，切入剩余数组的首项，再次迭代，直到无剩余数组。中间若出现某个数组的两个元素均存在与a中或b中则返回False，直到遍历完成，最后返回True.
ps：中间很多步骤都没有进行优化省略，可以对剩余数组进行时间上的优化，有很多重复无用的步骤，这里因为懒就没有去深究了。

```
class Solution:
    def possibleBipartition(self, N: int, dislikes: List[List[int]]) -> bool:
        #边界判定，个人认为长度为1应该False的
        n = N
        if n == 0:
            return False
        if not dislikes:
            return True
        #创建二分数组，哈希存储对立数组
        a = [0]*n
        b = [0]*n
        #初始化dislikes数组中未纳入二分数组中的元素组
        t = dislikes
        #对剩余数组t进行二分编排、压缩
        while t:
            dislikes = t
            #设立标志数组确保每轮二分编排都对剩余数组t进行压缩
            s = t
            #重新生成剩余数组t
            t = []
            for i in range(0,len(dislikes)):
                #判断dislikes数组中的元素组是否都存在于二分数组的某一边，返回False
                if a[dislikes[i][0] - 1] == 1 and a[dislikes[i][1] - 1] == 1:
                    return False
                if b[dislikes[i][0] - 1] == 1 and b[dislikes[i][1] - 1] == 1:
                    return False
                #判断dislikes数组中的元素组元素归属，反面思想
                if a[dislikes[i][0] - 1] == 1:
                    b[dislikes[i][1] - 1] = 1
                elif b[dislikes[i][0] - 1] == 1:
                    a[dislikes[i][1] - 1] = 1
                elif a[dislikes[i][1] - 1] == 1:
                    b[dislikes[i][0] - 1] = 1
                elif b[dislikes[i][1] - 1] == 1:
                    a[dislikes[i][0] - 1] = 1
                else:
                #未存在与任一二分数组中，则重新储存与剩余数组t
                    t.append([dislikes[i][0],dislikes[i][1]])
            #判断数组t中的元素是否存在与二分数组中，若是都不存在则剩余数组完全独立，归入首元素渗透进入
            if s == t:
                a[t[0][0] - 1] = 1
                b[t[0][1] - 1] = 1
                t.pop(0)
        #所有dislikes数组元素组均分配完毕，没有矛盾组
        return True
```

