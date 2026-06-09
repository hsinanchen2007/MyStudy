所分出的两个列表的均值均等于列表A的均值，代码如下
```
class Solution:
    def splitArraySameAverage(self, A: List[int]) -> bool:  # 每个列表的平均数与A的平均数相等
        A.sort()
        n = len(A)
        ave = sum(A)/n
        def findlist(A, i, s):
            ll = len(A)
            if i==0 and s==0:
                return True
            if i<=0:
                return False
            for j in range(ll-i+1):      # 保证第一个数字位置加上总位数小于A的长度
                if j>0 and A[j]==A[j-1]:      # 除去重复的情况
                    continue
                if findlist(A[j+1:], i-1, s-A[j]):
                    return True
            return False
        
        for i in range(1, n//2+1):   #列表长度
            if  abs(i*ave-int(i*ave))>1e-10:   # 整数和必须为整数 可能引入无限小数
                continue
            if findlist(A, i, int(i*ave)):
                return True
        return False
```
