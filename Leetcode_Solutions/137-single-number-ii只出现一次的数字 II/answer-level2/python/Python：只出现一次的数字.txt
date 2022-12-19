### 解题思路
这个位运算真的厉害了，我自问不会，努力学习ing~
分享我最喜欢的纯数学法

### 代码

```python3
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        return (3*sum(set(nums))-sum(nums))//2
```