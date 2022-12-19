### 解题思路
从左到右遍历。注意可能存在多余三个组的可能，这种情况下合并除了前两个组之后的所有组依然可以分成三个组。本来想优化一下但好像可能反而时间要更久
### 代码

```python3
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        avg = sum(A)/3
        tmp = avg
        count = 0
        for j in A:
            tmp -= j
            if tmp == 0:
                tmp = avg
                count += 1
        if count >= 3:
            return True
        return False



```