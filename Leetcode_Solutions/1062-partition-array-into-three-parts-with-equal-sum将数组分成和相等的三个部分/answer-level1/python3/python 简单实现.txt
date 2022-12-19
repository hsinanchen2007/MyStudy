### 解题思路
1. 对列表整体求和sum_A，如果sum_A%3 != 0，则A不可能三等分，否则转2
2. sum_A整除3得到3等分的和section_sum，算出每一部分的和
3. 遍历一遍数组，找出是否有3段连续和为section_sum，若存在则返回True，否则返回False

### 代码

```python3
class Solution(object):
    def canThreePartsEqualSum(self, A):
        sum_A = sum(A)
        if sum_A % 3 != 0:
            return  False
        section_sum = sum_A // 3
        sum_part, num_part = 0, 0
        for i in A:
            sum_part += i
            if sum_part == section_sum:
                sum_part = 0
                num_part += 1
                if num_part == 3:
                    return True   

        return False


```