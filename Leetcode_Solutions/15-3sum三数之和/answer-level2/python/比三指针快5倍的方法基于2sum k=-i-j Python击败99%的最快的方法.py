三个数之和为0一定只能是++- 或者+--才能凑出来，三指针方法会在很多--- +++的地方算，其实是做无用功。
所以一开始就把+ -分好，分别在+ - 两部分去用指针，会快很多很多。

时间比较：
三指针 1200ms
本方法（改进的三指针） 200ms

```
    def threeSum(self, nums):
        dic = {}
        res = []
        for i in nums: 
            dic[i] = dic.get(i,0) + 1
        #思路：首先分开正负，因为一定是+ + - 或者- - +来凑数，
        pos = [i for i in dic if i > 0]
        neg = [i for i in dic if i < 0]
        neg.sort()
        
        if 0 in dic and dic[0] >= 3:
            res.append([0,0,0])
            
        for i in pos:
            for j in neg:
                k = -i-j
                print("要凑的数:",k)#先求出目标
                if k in dic:
                    print("k在dic里")
                    if (k==i or k==j) and dic[k] >= 2:
                        #[-1,-1,2]这种情况，出现相同的两个数
                        res.append([i,k,j])
                    elif i > k > j:
                        #+ + - 或者+ - -的情况，k是一个中间数
                        res.append([i,k,j])
#                    if k < j:
#                        #-6=-8-(-2) 这种情况，k已经比最-的还要-，
#                        #就不可能从dict里找出来这么-的数来凑
#                        #其实也可以不考虑这种情况，也不会节省多少时间
#                        break
        return res
```
