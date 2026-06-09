![图片1.png](https://pic.leetcode-cn.com/5b749afdd1064765643d021bade572ae202606d97e9c2f6d27083b7157a54cf9-%E5%9B%BE%E7%89%871.png)

思路： 
1. 从后往前找到打破降序（从后往前看）的点，也就A[i-1] > A[i]，这个点就是i-1。
2. 然后从i往后查找小于A[i-1]的所有数中的最大值，这里注意如果两个最大值相同取前面的。另外，此时往后找的序列应该是升序的，所以一旦A[i-1] <= A[j]，查找结束。

小结：就是先从前往后遍历，找到位置，再从该位置往后遍历。最差情况是O(2N)吧？

仅供参考，欢迎批评指正！

```
class Solution:
    def prevPermOpt1(self, A: List[int]) -> List[int]:
        n = len(A)
        for i in range(n - 1, 0, -1):
            if A[i] < A[i - 1]:
                point = i
                for j in range(i, n):
                    if A[i - 1]  > A[j]:
                        if A[j] != A[j - 1]: point = j
                    else: break
                A[i - 1], A[point] = A[point], A[i - 1]
                break
        return A
```


