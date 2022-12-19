### 解题思路
我的思路：先遍历平方，时间为o(n)；再快速排序，时间o(nlogn)
	

复杂度分析：                                                             
	• 时间复杂度：o(nlogn)
	• 空间复杂度：o(n)



### 代码

```python
class Solution:
    def sortedSquares(self, A: List[int]) -> List[int]:
        for i in range(len(A)):
            A[i] = A[i]**2
        A.sort()
        return A
```