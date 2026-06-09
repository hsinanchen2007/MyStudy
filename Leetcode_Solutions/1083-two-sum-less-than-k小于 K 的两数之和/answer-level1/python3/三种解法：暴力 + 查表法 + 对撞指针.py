1. 暴力法 O(n^2)
2. 查表法 O(n * logn)
3. 对撞指针 O(n * logn) 但是比方法2执行要快一些

# 1. 暴力
```
class Solution:
    def twoSumLessThanK(self, A: List[int], K: int) -> int:
        n = len(A)
        gap = float('inf')
        for i in range(n):
            for j in range(i+1, n):
                one = A[i] + A[j]
                if one < K:
                    gap = min(gap, K - one)
        
        return K - gap if gap != float('inf') else -1
```

# 2. 查表法
先排序，然后把排序后的数组当成一张有序的表；这个过程 n * logn
然后遍历数组，每次都二分查找，小于target - a的最大的数；每次二分查找logn, 查找n次；n * logn
顺便提一句，这里使用bisect --- 数组二分查找算法：有兴趣可以看下文档：https://docs.python.org/zh-cn/3/library/bisect.html
```
class Solution:
    def twoSumLessThanK(self, A: List[int], K: int) -> int:
        # 暴力法 n^2
        # 查表 n * logn
        A.sort()
        gap = float('inf')
        for i in range(len(A)):
            a = A[i]
            idx = bisect.bisect_left(A, K - a)
            if idx > 0 and i != idx - 1:
                gap = min(gap, K - a - A[idx - 1])
            
        return K - gap if gap != float('inf') else -1
```

# 3.对撞指针
方法2，时间战胜了40%的算法；想想哪里能优化；是第二个查找阶段
先排序 n * logn
对撞指针遍历，这里很关键；
如果A[low] + A[high] >= K : high -= 1; 
如果A[low] + A[high] < K : compare and low += 1
这个过程是不会漏掉关键值的；自己推算一遍即可；
```
class Solution:
    def twoSumLessThanK(self, A: List[int], K: int) -> int:
        # 暴力法 n^2
        # 查表 n * logn
        # 双索引
        A.sort()
        gap = float('inf')
        l, h = 0, len(A) - 1
        while l < h:
            key = A[l] + A[h]
            if key < K:
                gap = min(gap, K - key)
                l += 1
            else:
                h -= 1
        return K - gap if gap != float('inf') else -1
```
方法3，可以战胜80%