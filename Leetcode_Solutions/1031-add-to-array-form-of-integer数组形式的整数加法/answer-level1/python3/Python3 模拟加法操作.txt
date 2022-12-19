### 解题思路
模拟两数相加，应该是很简单的思路

### 代码

```python3
class Solution:
    def addToArrayForm(self, A: List[int], K: int) -> List[int]:
        count = 0
        for i in range(len(A) - 1, -1, -1):
            result_new = K + A[i]
            A[i] = result_new % 10
            K = result_new // 10
            if K == 0:
                return A
        else:
            for j in range(1, len(str(K)) + 1):
                A.insert(0, K % 10)
                K = K // 10
        return A

```