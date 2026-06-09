### 解题思路
三段之和相等，只要求首尾两段之和等于sum//3即可，用两个指针分别指向左右，想中间移动，只有相等时停止，最后比较。

### 代码

```python3
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        if not A:
            return 

        Sum=sum(A)
        if Sum%3:
            return False
        size=len(A)
        if size<3:
            return False
        subSum=Sum//3

        leftSum, rightSum = A[0], A[size-1]
        i, j = 1, size-2

        while i<j and leftSum!=subSum:
            leftSum+=A[i]
            i+=1
        while i<j and rightSum!=subSum:
            rightSum+=A[j]
            j-=1
        if leftSum==subSum and rightSum==subSum:
            return True 
        else:
            return False
```