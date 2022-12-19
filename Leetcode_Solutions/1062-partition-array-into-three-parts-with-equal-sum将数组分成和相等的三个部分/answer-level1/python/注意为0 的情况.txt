### 解题思路
注意分区中和为0 的情况，这种情况出现的次数 >=3 即可
### 代码

```python3
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        if not A or (sum(A) != 0 and sum(A) % 3 != 0):
            return False
        partition = sum(A) // 3
        count, i, times = 0, 0, 0
        while i < len(A):
            count += A[i]
            # 后面可能有负数啊 并不是大于了之后就返回false
            if count == partition:        
                count = 0
                times += 1
            i += 1
        return times == 3 or partition == 0 and times >= 3

```