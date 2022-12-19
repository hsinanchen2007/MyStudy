### 解题思路

说实话，我觉得我的解法不是很优秀，就是遍历B中的元素，index从0到n,
然后算出B[index]在A中的位置，这个时候有两种情况：
1）在0~m之间，ok，插入到应有位置，同时A中元素依次后移一位，同时m的长度加1
2）不在0~m之间，ok，说明B中所有的元素都比较大，应该排在尾部

### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        if m + n > len(A):
            return 
        o = m + n
        nn = 0
        for i in range(n):
            for idx in range(0 , m):
                if B[i] <= A[idx]:
                    for j in range(len(A) - 1 , idx , -1):
                        A[j] = A[j - 1]
                    A[idx] = B[i]
                    m += 1
                    nn += 1
                    break
        if nn != n:
            for i in range(nn , n):
                A[m] = B[i]
                m += 1
        

        
```