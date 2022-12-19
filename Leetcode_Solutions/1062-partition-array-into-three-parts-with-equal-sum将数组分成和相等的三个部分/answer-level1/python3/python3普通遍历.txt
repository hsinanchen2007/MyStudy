### 解题思路
python3普通遍历

### 代码

```python3
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        sum_A = sum(A)
        if sum_A % 3:
            return False
        part_val = sum_A // 3

        cur_sum = 0
        total_count = 0
        len_A = len(A)
        for index in range(len_A):
            cur_sum += A[index]
            if cur_sum == part_val:
                total_count += 1
                cur_sum = 0
                if total_count == 2:
                    return index != len_A - 1

        return False

```