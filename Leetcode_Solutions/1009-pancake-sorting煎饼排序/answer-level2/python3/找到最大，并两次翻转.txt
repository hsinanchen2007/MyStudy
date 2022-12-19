### 解题思路
同官方题解思路，找到最大元素，通过两次翻转放到最后。对N-1数组继续执行。官方代码简洁，可惜自己太笨理解不能

### 代码

```python3
class Solution:
    def pancakeSort(self, A: List[int]) -> List[int]:
        res = []

        def findMax(last):
            k = 1
            num = A[k - 1]
            for i in range(2, last + 1):
                if A[i - 1] > num:
                    num = A[i - 1]
                    k = i
            return k

        def place(last):
            k = findMax(last)
            if k != last:
                if k != 1:
                    A[:k] = reversed(A[:k])
                    res.append(k)
                A[:last] = reversed(A[:last])
                res.append(last)
        for i in range(len(A), 1, -1):
            place(i)

        return res
```