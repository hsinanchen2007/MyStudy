### 解题思路
1. 判断给定数组和是否是3的正数倍， 如果不是则 return False；
2. W = 给定数组和的三分之一， i，j记录子数组的两端边界；
3. 当子数组的和等于W时，res数组新增一个True， i和j同时移位到下一个子数组的起始位置， 并重置子数组和；
4. 当子数组的和不等于W时，j + 1；
5. 最后判断res数组的长度是否等于3， 不是则返回False， 否则返回True。

### 代码

```python3
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        if len(A) < 1:
            return False
        sum_ = sum(A)
        if sum_ % 3 != 0:
            return False
        W = sum_//3
        res = []
        i = 0
        j = 0
        sub = 0
        while i <=j and j < len(A) and i < len(A):
            sub += A[j]
            if sub == W:
                res += [True]
                j += 1
                i = j
                sub = 0
            else:
                j += 1
        if len(res) < 3:
            return False
        return True

```