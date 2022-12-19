### 解题思路
对于等分和这类问题：
1. 构造存储了前N个数之和的列表
2. 依次**分段**找到位于等分值处的下标
3. 如果下标个数不小于等分数且最后一个下标不是最后一个数，返回true

细节：
1. 若数组长度小于等分数，返回false
2. 注意最后一个下标，若是前缀和数组的最后一个，返回false

时间复杂度：O(N)
空间复杂度：O(N)

### 代码

```python3
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        if len(A) < 3:
            return False

        sum_A = []
        sum_a = 0
        cursor = 0

        for i in A:
            sum_a += i
            sum_A.append(sum_a)

        if sum_A[-1] % 3 != 0:
            return False

        base_line = sum_A[-1] / 3

        for i, n in enumerate(sum_A):
            if n == base_line:
                cursor = i
                break

        for i, n in enumerate(sum_A[cursor+1:]):
            if n == base_line * 2:
                if i + cursor + 1 < len(A) - 1:
                    return True

        return False
```