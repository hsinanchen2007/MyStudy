### 解题思路
将偶数位置不匹配的存一个集合，奇数不匹配的存一个集合。遍历偶数集合，调换两个集合的元素位置。

### 代码

```python3
class Solution:
    def sortArrayByParityII(self, A: List[int]) -> List[int]:
        x = 0
        a_set = []
        b_set = []
        while x < len(A):
            if (x % 2 != 0 and A[x] % 2 ==0 ):
                a_set.append(x)
            elif (x % 2 != 1 and A[x] % 2 == 1 ):
                b_set.append(x)
            x = x + 1
        for a in a_set:
            b = b_set.pop()
            tmp = A[a]
            A[a] = A[b]
            A[b] = tmp
        return A

```