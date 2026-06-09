### 解题思路
定义两个数组 l_max 和 r_min，分别代表从左边看到某个位置的最大值，和从右边看到某个位置的最小值，这样只要到了某个位置，左边的最大值都小于右边的最小值，题目要求就满足了。

### 代码

```python3
class Solution:
    def partitionDisjoint(self, A: List[int]) -> int:
        l_max = [0 for i in range(len(A))]
        r_min = [0 for i in range(len(A))]
        l_max[0] = A[0]
        r_min[-1] = A[-1]
        for i in range(1, len(A)):
            l_max[i] = max(A[i], l_max[i-1])
        for i in range(len(A)-2, -1, -1):
            r_min[i] = min(A[i], r_min[i+1])

        for i in range(1, len(A)):
            if l_max[i-1] <= r_min[i]:
                return i

```