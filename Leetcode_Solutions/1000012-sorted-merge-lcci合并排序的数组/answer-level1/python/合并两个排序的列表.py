### 解题思路
用双指针的方法
1、注意边界条件：空列表
2、准备一个空列表C，同时遍历A和B，那个数小，就把那个数放入C，小的数的指针往下，大的数的指针不动，直到遍历完其中一个列表；
3、如果哪个列表还没有遍历完，就把那个列表剩下的数全都放入C；
4、将C赋给A，记得是A[:] = C,而不是A = C

### 代码

```python
class Solution(object):
    def merge(self, A, m, B, n):
        """
        :type A: List[int]
        :type m: int
        :type B: List[int]
        :type n: int
        :rtype: None Do not return anything, modify A in-place instead.
        """
        C = []
        if A == None:
            return B
        elif B == None:
            return A
        i = 0
        j = 0
        while (i < m and j < n):
            if A[i] <= B[j]:
                C.append(A[i])
                i = i + 1
            else:
                C.append(B[j])
                j = j + 1

        if i<m:
            for k in range(i,m):
                C.append(A[k])
        if j<n:
            for k in range(j,n):
                C.append(B[k])
        A[:] = C
```