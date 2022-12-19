解题思路：
首先，如果数组长度 < 3，返回 False。
因为每一等分的和是固定的，先计算出这个固定的和（equal_sum），然后从前向后遍历数组并记录cur_sum，并记录和为equal_sum的子数组个数。如果找到**至少**三个子数组，且遍历完之后cur_sum为0，返回True；否则返回False。
```
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        if len(A) < 3:
            return False
        equal_sum = sum(A)/3
        cur_sum = 0
        get_equal = 0
        for each in A:
            cur_sum += each
            if cur_sum == equal_sum:
                get_equal += 1
                cur_sum = 0
        if get_equal >= 3 and cur_sum == 0:
            return True
        else: return False
```
