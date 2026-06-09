### 解题思路
和其他人思路差不多，提供一个python版本

### 代码

```python3
class Solution:
    def matrixScore(self, A: List[List[int]]) -> int:
        # 行移动
        for i in range(len(A)):
        # 第一个数不为 1   则需要移动 否则不变
            if A[i][0] == 1:
                continue
            temp = []
            temp = [1 if x == 0 else 0 for x in A[i]]
            A[i] = temp
        # 列移动
        for i in range(len(A[0])):
            # 先判断是否需要移动
            zero = 0
            one = 0
            for j in range(len(A)):
                if A[j][i] == 0:
                    zero += 1
                else:
                    one += 1
            # 每一列 0 比 1 多 则移动
            if zero > one:
                for j in range(len(A)):
                    if A[j][i] == 0:
                        A[j][i] = 1
                    else:
                        A[j][i] = 0
        # 输出
        result = 0
        for i in range(len(A)):
            temp = 0
            for j in range(len(A[0])):
                temp = temp * 2 + A[i][j]
            result += temp
        return result

```