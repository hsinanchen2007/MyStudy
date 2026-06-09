### 解题思路
1.创建字典
2.返回key对应的value值

### 代码

```python3
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        dt={}
        for d in nums:
            dt[d]=dt.get(d,0)+1
        return dt.get(target,0)
```