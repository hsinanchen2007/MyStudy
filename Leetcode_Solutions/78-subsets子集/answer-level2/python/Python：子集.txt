### 解题思路
来自Donald E Knuth的X算法
很经典的子集判断，用的是位运算思想
具体思路看官方解，用二进制表示每一个元素
### 代码

```python3
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        output = []
        for i in range(2**n, 2**(n + 1)):
            bitmask = bin(i)[3:]
            output.append([nums[j] for j in range(n) if bitmask[j] == '1'])
        return output

```