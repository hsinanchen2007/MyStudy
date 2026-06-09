### 解题思路
    1.时间复杂度O(M+N) 空间复杂度O(M+N):     
        1) 创建额外的数组空间，ans
        2) 从头至尾对A于B逐一判断，将较小的数填入ans
        3) 当某一数组遍历结束后，只增加另一个数组的值即可
            

    2. 时间复杂度O(M+N) 空间复杂度O(1):  
        1) 从后向前开始遍历，将A与B较大的数，向A的最后的空间进行赋值
        2) 当B赋空时，进行输出
        3）在A为空的情况下，将B的值逐一赋给A即可
### 代码

```py
class Solution:
    # 时间复杂度O(M+N) 空间复杂度O(1)
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
            i,j = m-1,n-1
        while j >=0 or i >=0:
            if j == -1:
                break
            elif i == -1:
                A[j] = B[j]
                j -= 1
            elif A[i] > B[j]:
                A[i+j+1] = A[i]
                i -= 1
            else:
                A[i+j+1] = B[j]
                j -= 1
```
```py
    # 时间复杂度O(M+N) 空间复杂度O(M+N)
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        i,j = 0,0
        ans = []
        while j <n or i<m:
            if i ==m:
                ans.append(B[j])
                j += 1
            elif j ==n:
                ans.append(A[i])
                i += 1
            elif A[i] > B[j]:
                ans.append(B[j])
                j += 1
            else:
                ans.append(A[i])
                i += 1
        A[:] = ans
```