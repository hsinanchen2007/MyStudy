### 解题思路
我一直喜欢能用纯数学解决的算法，这道题明显可以，虽然使用了外部空间
其实不使用外部空间不可能，至少要O(1)的程度，快排、堆、归并都能达到目的，看官方思路有位运算可以解决，好久没用了，都没有想到

### 代码

```python3
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        return 2*sum(set(nums))-sum(nums)
```