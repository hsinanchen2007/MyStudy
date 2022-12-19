### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        # 作者：cui-jin-hao-_official
        A.sort()
        moves = 0
        for i in range(1, len(A)):
            if A[i] <= A[i-1]:
                moves += (A[i-1] - A[i] + 1)
                A[i] = A[i-1] + 1
        return moves

        # 该方法在第54个用例时会超时
        # res = []
        # moves = 0
        # for item in A:
        #     if item not in res:
        #         res.append(item)
        #     else:
        #         moves += 1
        #         item += 1
        #         while item in res:
        #             moves += 1
        #             item += 1
        #         res.append(item)
        # return moves
                

```