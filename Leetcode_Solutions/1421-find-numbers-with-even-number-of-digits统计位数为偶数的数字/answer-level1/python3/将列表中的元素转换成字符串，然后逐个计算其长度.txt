### 解题思路
这道题还是挺简单的，逐个计算整数列表中的元素长度，先转换成字符串，然后计算字符串的长度就行了

### 代码

```python3
class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        i = 0
        for num in nums:
            strnum = str(num)
            lennums = len(strnum)
            if lennums%2 ==0:
                i += 1
        return i

```