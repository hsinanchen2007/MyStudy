### 解题思路
- 先求两个数组的差值diff = sum(a)-sum(b), 如果为奇数直接return [], 因为交换任何数得到的diff一定是两个数字差值的2倍
- 然后将数组b作为集合, 遍历数组a, 判断其每个元素-diff//2是否在b集合中, 在的话即为所求

### 代码

```python

class Solution:
    def findSwapValues(self, array1: List[int],
                       array2: List[int]) -> List[int]:
        diff = sum(array1) - sum(array2)
        if diff & 1: return []
        diff >>= 1
        s2 = set(array2)
        for a in array1:
            if a - diff in s2:
                return [a, a - diff]
        return []
```