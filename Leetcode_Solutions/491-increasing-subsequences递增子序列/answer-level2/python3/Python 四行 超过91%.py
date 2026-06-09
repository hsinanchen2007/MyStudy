### 解题思路
来自转载
### 代码

```python3
class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        # 先把所有符合要求的都生成出来（包括空和单个字符）
        # 然后筛选掉长度不符合要求的
        subs = {()}
        for num in nums:
            subs |= {sub + (num,) for sub in subs if not sub or sub[-1] <= num}
        return [list(sub) for sub in subs if len(sub) >= 2]
```