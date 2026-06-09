### 解题思路
1. 连续的正整数序列可看作是等差数列的特殊情况；
2. 假设数列长度为`n`，且第一项为`a1`，最后一项为`an`，当数列之和`sum`等于`target`的时候，该数列即为题解, `sum = target = (a1 + an) * n / 2`；
3. 再假设所可能的解的集合为：`（1, 2, 3, ... , x - 1, x）`，题意为至少含有两个数，推出`x - 1 + x <= target`，`x`为解集中的上边界。 x = (target + 1) // 2
4. 把`an = a1 + n -1`带入第二步中的等式得：`n^2 + (2 * a1) * n - 2 * target = 0`，解一元二次方程可以求出`n = int((1 - 2 * i + math.sqrt(pow((2 * i-1), 2) + 8 * target)) / 2)`
5. 当sum等于target的时候可得解，按顺序从1到x累积所有解；

### 代码

```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        if target < 3:return []
        res = []
        x = (target + 1) // 2
        import math
        for i in range(1, x):
            n = int((1 - 2 * i + math.sqrt(pow((2 * i-1), 2) + 8 * target)) / 2)
            if (2 * i + n - 1) * n / 2 == target:
                res.append(list(range(i, i + n)))
        return res


```