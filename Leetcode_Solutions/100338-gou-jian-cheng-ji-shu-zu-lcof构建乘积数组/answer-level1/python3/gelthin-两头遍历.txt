### 解题思路

参考[【构建乘积数组】：对称遍历](https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof/solution/gou-jian-cheng-ji-shu-zu-dui-cheng-bian-li-by-huwt/)

构造两个数组:
+ C[i] 代表 A[0]*...*A[i-1]
+ D[i] 代表 A[n-i]*....A[n-1]

然后 B[i] = C[i]*D[n-i-1]

提交错了一次，由于不小心下标没写对，报了BUG 


### 代码

```python3
class Solution:
    def constructArr(self, a: List[int]) -> List[int]:
        n = len(a)
        C = [1]
        for i in range(n): #C[0] =1, C[i] = A[0]*..。*A[i-1]
            C.append(a[i]*C[i])
        
        D  = [1]
        for i in range(n):  # D[0] = 1, D[i] 代表 A[n-i]*...*A[n-1]
            D.append(D[i]*a[n-i-1])
        B = []
        for i in range(n):
            B.append(C[i]*D[n-1-i])
        return B
```