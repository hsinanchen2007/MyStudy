### 解题思路
设置左右两个指针：
1. 如果左指针所指位置为奇数，有指针所指位置为偶数，则交换，左右各走一步。
2. 如果左指针所指为止为偶数，保持右指针不变，左指针走一步。
3. 如果左指针所指为止为奇数，保持左指针不变，右指针走一步。
4. 

### 代码

```python3
class Solution:
    def sortArrayByParity(self, A: List[int]) -> List[int]:
        left = 0
        right = len(A)-1

        while left < right:
            if A[left] % 2 == 1 and A[right] % 2 == 0:
                A[left], A[right] = A[right], A[left]
                left += 1
                right -= 1
            elif A[left] % 2 == 0:
                left += 1
            elif A[left] % 2 == 1:
                right -= 1
        
        return A
```