### 解题思路
由题目可知，0-n是一个等差数列（公差为1，项数为输入数列长度+1），虽然输入数列少了
未知的其中一项，但是不管它少的是哪一项，这个原始数列的总和以及项数是不变的，所以
原始数列总和与输入数列总和的差就是缺少的那一项，并不需要对输入数列重新排序。

1. 原始数列总和可以用公式直接算出来。
2. 输入数列的总和可以由sum()直接算出来。
3. 互减得到最后结果。

### 代码

```python
class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return len(nums)*(len(nums)+1)//2 -sum(nums)
```