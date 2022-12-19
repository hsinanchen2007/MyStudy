### 解题思路
python3，完全是列表生成式的玩法，一句话的事
### 代码

```python3
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        return [ [ nums[i] for i in range ( len ( nums ) ) if ( x >> i ) & 1 == 1 ] for x in range ( 1 << len ( nums ) ) ]
```