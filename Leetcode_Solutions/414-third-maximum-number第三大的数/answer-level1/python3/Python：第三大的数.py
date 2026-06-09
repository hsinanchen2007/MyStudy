### 解题思路
O(n)?那是不是sort()还不能使用，毕竟它只是log……

### 代码

```python3
class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        ans=sorted(list(set(nums)))
        return ans[-3] if len(ans)>2 else ans[-1]
```