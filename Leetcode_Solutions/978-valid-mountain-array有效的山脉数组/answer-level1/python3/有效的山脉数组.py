### 解题思路
我的思路：首先遍历数组，判断是否存在一个大于前i个数的数，直到遇到一个小于前一个的数（这里设一个mark标记），之后判断是否一直是递减。
即：必须先递增，后递减。
	

复杂度分析：                                                             
	• 时间复杂度：o(n)
	• 空间复杂度：o(1)



### 代码

```python
class Solution:
    def validMountainArray(self, A: List[int]) -> bool:
        length = len(A)
        if length < 3:
            return False
        mark = 0
        for i in range(length-1):
            if A[i] < A[i+1] and mark == 0:
                mark = 0
            elif A[i] == A[i+1]:
                return False
            elif A[i] > A[i+1] and i != 0:
                mark = 1
            else:
                return False
        if mark:
            return True
        else:
            return False

```