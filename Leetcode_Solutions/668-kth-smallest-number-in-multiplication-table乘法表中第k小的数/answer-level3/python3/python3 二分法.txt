思路1，暴力法
将乘法表所有数存入一个列表，然后sort()，返回第k小的数字。超时的同时还会占用很大的空间。

思路2，二分法
整个乘法表中最小的数是1，最大的数为mn，并且每行都是有序的。
这意味着我们可以寻找中间数 mid=(low+high)/2 ，通过统计每行小于mid数的数量总和，来判断整个乘法表中小于mid数的个数,以此收缩查找范围
```
class Solution:
    def findKthNumber(self, m: int, n: int, k: int) -> int:
        def helper(mid,m,n):
            count = 0
            for i in range(1,m+1):
                count += min(mid//i,n)   #计算每一行小于mid数的个数
            return count
        
        low,high = 1,m*n+1               
        while low < high:
            mid = (low+high)//2
            count = helper(mid,m,n)
            if count>=k:
                high = mid
            else:
                low = mid +1
        return low
```
