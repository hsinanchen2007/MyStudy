### 解题思路
分别将偶数位和转化为列表的奇数位分别相乘再合起来即可

### 代码

```python3
class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        times, ele = 0, 1
        res = []
        while len(nums) >= ele:
            res += ([nums[ele]] * nums[times])
            times, ele = times+2, ele+2
        return res

```